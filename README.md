# PieroBlankProject

- [Introducción](#Introducción)
- [Montaje](#Montaje)
- [Calibración de los sensores](#calibración-de-los-sensores)
  - [Sensores laser VL53L0X](#sensores-laser-vl53l0x)
- [Programación del Piero-DIY](#programación-del-piero-DIY)
  - [Controlador reactivo](#controlador-reactivo)
  - [Encoders de los motores](#encoders-de-los-motores)

## Introducción


## Montaje
Se adjuntan, a continuación, los pasos del montaje del Piero-DIY:

En primer lugar pusimos los componentes del piero montados a modo de banco de pruebas para ir probando parte de la programación de los motores, sensores, etc.

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/7b83e131-c530-452e-bcf4-3c4c22012277" alt="BancoDePruebas_Tapa" width="200" height="300" align="center">


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
### Sensores de distancia Sonar
El ensor de ultra sonidos UD-016 es capaz de medir distancias de entre 4 cm y 300 cm (con una precisión de 0.3cm +- 1%).
La salida analógica varía entre 0 y 5V y el rango de valores de salida del sensor varía entre 0 y 1015
Se toman las medidas de ambos sensores de forma experimental 
Sensor L:

Medida Real (cm) | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 | 100 | 110 | 120 | 130 | 140 | 150 | 175 | 200 | 225 | 250
---|----|----|----|----|----|----|----|----|----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----
Sensor | 32 | 69 | 99 | 130 | 162 | 190 | 228 | 253 | 293 | 330 | 360 | 392 | 430 | 462 | 497 | 580 | 678 | 756 | 836

Sensor R:

Medida Real (cm) | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 | 100 | 110 | 120 | 130 | 140 | 150 | 175 | 200 | 225 | 250
---|----|----|----|----|----|----|----|----|----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----
Sensor | 29 | 66 | 96 | 130 | 160 | 192 | 225 | 260 | 294 | 326 | 360 | 395 | 427 | 463 | 497 | 578 | 665 | 746 | 830


Representamos la recta ideal de medidas (si el sensor fuese perfecto) con respecto a la obtenida experimentalmente.Realizamos la calibración simultanea 
Realizaremos la calibración simultanea de los dos sensores. Para identificarlos, los distingueremos como sensor izquierdo ("L") y sensor derecho ("R").

```
distancia_teorica=[10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 175, 200, 225, 250];
distancia_medida_L = [32, 69, 99, 130, 162, 190, 228, 253, 293, 330, 360, 392, 430, 462, 497, 580, 678, 756, 836];
distancia_medida_R = [29, 66, 96, 130, 160, 192, 225, 260, 294, 326, 360, 395, 427, 463, 497, 578, 665, 746, 830];figure()
grid on
hold on
plot(distancia_teorica,distancia_teorica)
plot(distancia_teorica,distancia_medida_L)
plot(distancia_teorica,distancia_medida_R)
legend("Recta ideal", "Recta experimental (L)", "Recta experimental (R)",'Location','northwest')
hold off
```
![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780545/e5c5df32-51ff-439d-8a15-0922776a0231)

Ahora, realizamos una regresión lineal para obtener la ecuacion de ajuste de los datos experimentales de cada sensor.

Y ajustaremos a una recta ya que es el polinomio que mejor se ajusta a simple vista
```
pol_L= polyfit(distancia_teorica,distancia_medida_L,1) 
pol_R = polyfit(distancia_teorica,distancia_medida_R,1)
```
Teniendo como resultados:
```
 pol_L =  [3.3698 -6.8969]
 pol_R =  [3.3396 -5.6439]
```
Representamos las rectas de ajuste con la ideal

´´´
x = 10:1:250;
y_teo = polyval([1 0],x);
y_exp_L = polyval(pol_L,x);
y_exp_R = polyval(pol_R,x);

figure()
grid on
hold on
plot(x,y_teo)
plot(x,y_exp_L)
plot(x,y_exp_R)
legend("Recta ideal","Recta experimental ajustada (L)", "Recta experimental ajustada (R)", 'Location','northwest')
hold off

´´´

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780545/cfebd189-7147-4493-818c-2ce952ab4edd)

 
Para ajustar la recta del sensor a la teórica, realizaremos un ajuste de 0 y de ganancia:

´´´

cero_L = 0-polyval(pol_L,0)
cero_R = 0-polyval(pol_R,0)
pol_L(1,2) = pol_L(1,2)+cero_L;
pol_R(1,2) = pol_R(1,2)+cero_R;

K_L = 400/polyval(pol_L,400)
K_R = 400/polyval(pol_R,400)

´´´

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

### Controlador reactivo

### Encoders de los motores

   
