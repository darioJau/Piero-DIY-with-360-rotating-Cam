# PieroBlankProject

## Calibración de los sensores
El VL53L0X es capaz de medir distancias de entre 50 y 2000 milímetros (medidas con un error asumible hasta 1200 mm max).
Representamos la recta ideal de medidas (si el sensor fuese perfecto) con respecto a la obtenida experimentalmente.

<img width="1216" alt="Captura de pantalla 2023-10-13 a las 10 10 41" src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/83056cb0-7e0c-473b-8b42-f6fd63c83aaa">

Ahora, realizamos una regresión lineal para obtener la ecuacion de ajuste de los datos experimentales.

<img width="452" alt="Captura de pantalla 2023-10-13 a las 10 11 55" src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/08f200c3-6ff9-43f1-aace-571f04aff274">

Y lo ajustamos a una parábola ya que es el polinomio que mejor se ajusta a simple vista

Representamos la recta de ajuste con la ideal

<img width="1219" alt="Captura de pantalla 2023-10-13 a las 10 13 19" src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/b08e514b-afe6-4e45-a10b-06333c8237bf">


 

Si quisieramos que la recta (ajustada) experimental coincidiese con la teórica, no sería posible realizar un control proporcional con una ganancia estática, dado que el valor de dicha ganancia debe de ir cambiando en función de la entrada. Por tanto, el control del sensor lo realizaremos mediante una LookUpTable, la cual contendrá la ganancia necesaria para realizar dicho ajuste en función de la medida que arroje el sensor. Calculamos dicho vector de ganancia:

<img width="1214" alt="Captura de pantalla 2023-10-13 a las 10 14 08" src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/ed8590f9-b485-4af9-ae14-69699ad31935">



Representando dicho vector de ganancias, vemos como el valor de la ganancia varía desde un valor menor a la unidad hasta un valor superior a ella, pasando por la unidad en el punto de corte entre las rectas teórica y experimental. Para comprobar la efectividad de dicho ajuste, representaremos las medias experimentales al haberles aplicado la ganancia calculada.

<img width="1214" alt="Captura de pantalla 2023-10-13 a las 10 15 02" src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/4224ff16-d6a9-411b-9be5-6d98bc5b2cfa">



Y comprobamos la mejora en el error después del ajuste:

<img width="1219" alt="Captura de pantalla 2023-10-13 a las 10 15 53" src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/2e9023c3-bb07-4382-be3f-d131b59701fe">

Es decir, el ajuste de ganancia variable supone un 75 % de mejora en la resolución del sensor.
Finalmente, lo implementaremos en Simulink mediante una LookUpTable.

<img width="1679" alt="Captura de pantalla 2023-10-13 a las 10 18 56" src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/6b16c1f6-72f0-4877-9a98-de98f01b4d3c">

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
