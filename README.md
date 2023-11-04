# PieroBlankProject

- [Introducción](#Introducción)
- [Montaje](#Montaje)
- [Calibración de los sensores](#calibración-de-los-sensores)
 - [Sensores laser VL53L0X](#sensores-laser-vl53l0x)
- [Programación del Piero-DIY](#programación-del-piero-DIY)

## Introducción


## Montaje
Se adjuntan, a continuación, los pasos del montaje del Piero-DIY:

En primer lugar pusimos los componentes del piero montados a modo de banco de pruebas para ir probando parte de la programación de los motores, sensores, etc.

![BancoDePruebas_Tapa](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/7b83e131-c530-452e-bcf4-3c4c22012277)

Una vez tenemos la caja firmada por el profesor, desmontamos este banco de pruebas y comenzamos con el montaje.
La caja es demasiado alta así que la cortaremos a una altura más acorde:
 
![Montaje 0](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/6f1feca4-fafe-4200-a8e4-44e676c9aec1)

Una vez cortada, presentamos y marcamos donde queremos colocar los componentes dentro de la caja:

![Montaje 1](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/e8a9b6f0-eb56-4f47-a389-5bd3d5e35cba)

Comenzamos a poner los soportes para los motores y el medidor de voltaje en la caja, haciendo sus respectivos agujeros y pegamos o atornillamos los elementos en la caja:

![Montaje 3](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/7e2d12e9-5a21-4b01-8ccb-ff72e3107fb7)
![Montaje 4](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/c3bec6bd-0d3a-47c8-8ced-30a340d6717d)

Por último, realizamos todas las conexiones como se precisa en este esquema:

 [ ESQUEMA DE CONEXIONADO ]


## Calibración de los sensores
### Sensores laser VL53L0X
El VL53L0X es capaz de medir distancias de entre 50 y 2000 milímetros (medidas con un error asumible hasta 1200 mm max).
Representamos la recta ideal de medidas (si el sensor fuese perfecto) con respecto a la obtenida experimentalmente.Realizamos la calibración simultanea 
Realizaremos la calibración simultanea de los dos sensores. Para identificarlos, uno de ellos tiene atado un cable por lo que, hasta que los coloquemos en su posición definitiva, se llamarán **"cc"** (con cable) y **"sc"** (sin cable).
```
distancia_teorica=[50:50:1200];
distancia_medida_cc=[55 107 158 214 274 320 370 420 465 515 565 610 655 700 750 800 840 900 930 980 1000 1030 1100 1150];
distancia_medida_sc=[57 108 160 217 270 320 375 423 475 520 565 620 660 710 750 800 850 895 930 980 1010 1030 1085 1140];
figure()
grid on
hold on
plot(distancia_teorica,distancia_teorica)
plot(distancia_teorica,distancia_medida_cc)
plot(distancia_teorica,distancia_medida_sc)
legend("Recta ideal", "Recta experimental (cc)", "Recta experimental (sc)",'Location','northwest')
hold off
```

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/6aa805ec-7f3c-45c9-a80d-fca415e16025)


Ahora, realizamos una regresión lineal para obtener la ecuacion de ajuste de los datos experimentales.

Y ajustaremos a una parábola ya que es el polinomio que mejor se ajusta a simple vista
```
pol_cc = polyfit(distancia_teorica,distancia_medida_cc,2)
pol_sc = polyfit(distancia_teorica,distancia_medida_sc,2) 
```
Teniendo como resultados:
```
 pol_cc =  [-0.0001    1.0895    1.3982]
 pol_sc =  [-0.0001    1.1217   -1.7490]

```


Representamos la recta de ajuste con la ideal
´´´
x = 50:1:1200;
y_teo = polyval([1 0],x);
y_exp_cc = polyval(pol_cc,x);
y_exp_sc = polyval(pol_sc,x);

figure()
grid on
hold on
plot(x,y_teo)
plot(x,y_exp_cc)
plot(x,y_exp_sc)
legend("Recta ideal","Recta experimental ajustada (cc)", "Recta experimental ajustada (sc)", 'Location','northwest')
hold off
´´´

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/52b91b0d-9681-4d2c-a533-42190ba50f21)

 

Si quisieramos que la recta (ajustada) experimental coincidiese con la teórica, no sería posible realizar un control proporcional con una ganancia estática, dado que el valor de dicha ganancia debe de ir cambiando en función de la entrada. Por tanto, el control de los sensores lo realizaremos mediante una LookUpTable, la cual contendrá la ganancia necesaria para realizar dicho ajuste en función de la medida que arroje el sensor. Calculamos dicho vector de ganancia:


´´´
K_cc = zeros(1,1151);
K_sc = zeros(1,1151);

for i = 1:1:1151
    K_cc(i) = y_teo(i)/y_exp_cc(i);
    K_sc(i) = y_teo(i)/y_exp_sc(i);
end

figure()
grid on
hold on
plot(x,K_cc)
plot(x,K_sc)
legend("Vector de ganancias (cc)", "Vector de gananacias (sc)", 'Location','northwest')
hold off
´´´


![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/09ddd94d-86fa-4323-a6a8-9893ad215d7b)



Representando dichos vectores de ganancias, vemos como el valor de la ganancia varía desde un valor menor a la unidad hasta un valor superior a ella, pasando por la unidad en el punto de corte entre las rectas teórica y experimental. Para comprobar la efectividad de dicho ajuste, representaremos las medias experimentales al haberles aplicado la ganancia calculada.

´´´
distancia_medida_ajustada_cc = zeros(1,24);
distancia_medida_ajustada_sc = zeros(1,24);
for i = 1:1:24
    distancia_medida_ajustada_cc(i)=distancia_medida_cc(i)*K_cc(distancia_medida_cc(i));
    distancia_medida_ajustada_sc(i)=distancia_medida_sc(i)*K_sc(distancia_medida_sc(i));
end

figure()
hold on
plot(distancia_teorica,distancia_teorica)
plot(distancia_teorica,distancia_medida_cc)
plot(distancia_teorica,distancia_medida_ajustada_cc, 'g')
title('Sensor con cable')
legend("Recta ideal","Recta experimental","Recta experimental ajustada con ganancia",'Location','northwest')
hold off
´´´

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/75e6c337-734b-4f53-8d98-7241564f5ffe)


´´´
figure()
hold on
plot(distancia_teorica,distancia_teorica)
plot(distancia_teorica,distancia_medida_sc)
plot(distancia_teorica,distancia_medida_ajustada_sc,'g')
title('Sensor sin cable')
legend("Recta ideal","Recta experimental","Recta experimental ajustada con ganancia",'Location','northwest')
hold off
´´´

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/62d96b0d-65e6-4b28-a620-81f712c051c2)



Y comprobamos la mejora en el error después del ajuste:

´´´
error_sin_ajuste_cc = 0; error_sin_ajuste_sc = 0;
error_con_ajuste_cc = 0; error_con_ajuste_sc = 0;
for i = 1:1:24
    error_sin_ajuste_cc = error_sin_ajuste_cc+abs(distancia_teorica(i)-distancia_medida_cc(i))/(24*distancia_teorica(i));
    error_sin_ajuste_sc = error_sin_ajuste_sc+abs(distancia_teorica(i)-distancia_medida_sc(i))/(24*distancia_teorica(i));
    error_con_ajuste_cc = error_con_ajuste_cc+abs(distancia_teorica(i)-distancia_medida_ajustada_cc(i))/(24*distancia_teorica(i));
    error_con_ajuste_sc = error_con_ajuste_sc+abs(distancia_teorica(i)-distancia_medida_ajustada_sc(i))/(24*distancia_teorica(i));
end

mejora_cc = (error_sin_ajuste_cc-error_con_ajuste_cc)*100/error_sin_ajuste_cc
 >> mejora_cc = 71.6842
mejora_sc = (error_sin_ajuste_sc-error_con_ajuste_sc)*100/error_sin_ajuste_sc
 >> mejora_sc = 75.8809
´´´

Es decir, el ajuste de ganancia variable supone un 71,7 % de mejora en la resolución del sensor con cable y un 75,8 % en la resolución del sensor sin cable.
Finalmente, lo implementaremos en Simulink mediante una LookUpTable.


![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/1f3e17a9-af00-48bd-961b-2eaa2de85a47)

Con los valores correspondientes en las Lookup Table de 1 dimensión:

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/8d442c64-4f74-4225-8650-9e3f8a910b5a)



A partir de esta calibración de los sensores, ya podemos trabajar con los datos que obtenemos de ellos y utilizarlos correctamente.

### Enlaces a los videos

 Piero moviéndose en línea recta con poca desviación en 3 metros
 
   https://drive.google.com/file/d/1Fcg5lSjv6q5oTs9PIr2WQYbxixgjgluB/view?usp=sharing
   
 Piero cambiando de color en función de los sensores
 
   https://drive.google.com/file/d/14OFnmPmH7kN_HsWogFRFNirAM9pgJrJD/view?usp=sharing
   
 Calibración de sensores, con varias medidas y su valor
 
   https://drive.google.com/file/d/1OfUWI7DMAnQXR0VtjLFuoKIydAzxXi-r/view?usp=sharing
   
 Piero evitando paredes (en un rincón y cerca de la puerta)
 
   https://drive.google.com/file/d/1iNn1hf_GFbhXEMNcsurv0YRRfCokeF8o/view?usp=sharing













## Programación del Piero-DIY


   
