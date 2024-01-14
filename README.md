
# PieroDIYProject Grupo 31 - Laboratorio de Robótica 2023-24

- [PieroDIYProject Grupo 31 - Laboratorio de Robótica 2023-24](#pierodiyproject-grupo-31---laboratorio-de-robótica-2023-24)
  - [Introducción](#introducción)
  - [Montaje](#montaje)
    - [Esquemas de montaje](#esquemas-de-montaje)
  - [Programación del Piero-DIY](#programación-del-piero-diy)
    - [Calibración de los sensores](#calibración-de-los-sensores)
      - [Sensores de distancia Sonar](#sensores-de-distancia-sonar)
    - [Senalizacion usando LEDS](#senalizacion-usando-leds)
    - [Motores](#motores)
    - [Controlador reactivo](#controlador-reactivo)
      - [Alertas](#alertas)
    - [Encoders de los motores](#encoders-de-los-motores)
      - [Calibración de los encoders](#calibración-de-los-encoders)
    - [Control en Bucle Abierto](#control-en-bucle-abierto)
      - [Calibración de los motores (zona muerta)](#Calibracion-de-los-motores)
      - [Piero](#piero)
    - [Control en Bucle Cerrado](#control-en-bucle-cerrado)
      - [ControladorBC](#controladorbc)
    - [Cinemática del Piero](#cinemática-del-piero)
      - [PieroCV](#pierocv)
      - [MCI: Modelo Cinemático Inverso](#mci-modelo-cinemático-inverso)
      - [MCD: Modelo Cinemático Directo](#mcd-modelo-cinemático-directo)
      - [Odometría](#odometría)
      - [Control del modelo (Simulación o Hardware)](#control-del-modelo-simulación-o-hardware)
    - [Control de orientación](#control-de-orientación)
  - [Modelos para salir de clase](#modelos-para-salir-de-clase)
    - [Salir de clase con Signal Builder](#salir-de-clase-con-signal-builder)
    - [Salir de clase con Matlab Function](#salir-de-clase-con-matlab-function)
    - [Salir de clase con Waypoints](#salir-de-clase-con-waypoints)
    - [Salir de clase con StateFlow](#salir-de-clase-con-waypoints-y-evitando-obstaculos)
    - [Salir de clase con Waypoints y evitando obstaculos](#salir-de-clase-con-waypoints-y-evitando-obstaculos)
  - [Implementación del Proyecto opcional](#parte-extra-implementación-de-una-video-cámara-y-de-un-mando-para-controlar-la-orientación-de-la-dicha-cámara-y-la-posición-del-piero)
    - [Introducción](#introducción-1)
    - [Programas utilizados](#programas-utilizados)
    - [Materiales usados](#materiales-usados)
    - [Implementación del mando](#implementación-del-mando)
    - [Programación y lógica de funcionamiento](#implementación-del-mando)
    - [Implementación de la cámara y su sistema de movimiento](#implementación-de-la-cámara-y-su-sistema-de-movimiento)
    - [Implementación de la pasarela Wifi para el Arduino Mega 2560](#implementación-de-la-pasarela-wifi-para-el-arduino-mega-2560)
    - [Diseño del flujo de Nodered](#diseño-del-flujo-de-nodered)
  - [Resumen de enlaces a todos los videos](#resumen-de-enlaces-a-todos-los-videos)

## Introducción


## Montaje
Se adjuntan, a continuación, los pasos del montaje del Piero-DIY:

En primer lugar pusimos los componentes del piero montados a modo de banco de pruebas para ir probando parte de la programación de los motores, sensores, etc.

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/7b83e131-c530-452e-bcf4-3c4c22012277" alt="BancoDePruebas_Tapa" width="500" align="center">


Una vez tenemos la caja firmada por el profesor, desmontamos este banco de pruebas y comenzamos con el montaje.
La caja es demasiado alta así que la cortaremos a una altura más acorde:
 
<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/6f1feca4-fafe-4200-a8e4-44e676c9aec1" alt="Montaje 0" width="500" align="center">

Una vez cortada, presentamos y marcamos donde queremos colocar los componentes dentro de la caja:

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/e8a9b6f0-eb56-4f47-a389-5bd3d5e35cba" alt="Montaje 1" width="500" align="center">

Comenzamos a poner los soportes para los motores y el medidor de voltaje en la caja, haciendo sus respectivos agujeros y pegamos o atornillamos los elementos en la caja:

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/7e2d12e9-5a21-4b01-8ccb-ff72e3107fb7" alt="Montaje 3" width="400" align="center">


<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/c3bec6bd-0d3a-47c8-8ced-30a340d6717d" alt="Montaje 4" width="400" align="center">

Por último, realizamos todas las conexiones como se precisa en este esquema:

### Esquemas de montaje


<img width="1131" alt="Captura de pantalla 2024-01-11 a las 20 21 14" src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/ba9d9e06-7b70-46c2-bee3-36e802767a1d">




## Programación del Piero-DIY

### Calibración de los sensores
#### Sensores de distancia Sonar
El ensor de ultra sonidos UD-016 es capaz de medir distancias de entre 4 cm y 300 cm (con una precisión de 0.3cm +- 1%).
La salida analógica varía entre 0 y 5V y el rango de valores de salida del sensor varía entre 0 y 1015
Se toman las medidas de ambos sensores de forma experimental <br>
Sensor L:

Real (cm) | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 | 100 | 110 | 120 | 130 | 140 | 150 | 175 | 200 | 225 | 250
---|----|----|----|----|----|----|----|----|----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----
Sensor | 32 | 69 | 99 | 130 | 162 | 190 | 228 | 253 | 293 | 330 | 360 | 392 | 430 | 462 | 497 | 580 | 678 | 756 | 836

Sensor R:

Real (cm) | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 | 100 | 110 | 120 | 130 | 140 | 150 | 175 | 200 | 225 | 250
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

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780545/e5c5df32-51ff-439d-8a15-0922776a0231" alt="Gráfica rectas ideales vs experimentales">


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

```
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
```

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780545/cfebd189-7147-4493-818c-2ce952ab4edd" alt="Gráfica rectas de regresión">
 
Para ajustar la recta del sensor a la teórica, realizaremos un ajuste de 0 y de ganancia:

```
cero_L = 0-polyval(pol_L,0)
cero_R = 0-polyval(pol_R,0)
pol_L(1,2) = pol_L(1,2)+cero_L;
pol_R(1,2) = pol_R(1,2)+cero_R;
K_L = 400/polyval(pol_L,400)
K_R = 400/polyval(pol_R,400)
```
Como resultado en la salida obtendremos una representación de la distancia medida en metros, a la que cada sensor detecta su obstáculo más cercano.

El diagrama implementado en SIMULINK es el siguiente:

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/02b28af8-1ccb-43de-bb8e-fce66550cf24" alt="Modelo Sonars">

### Senalizacion usando LEDS
Para la implementación de un sistema de señalización adecuado que defina claramente los estados en los que se encuentra el Piero, haremos uso del siguiente diagrama: 
<table>
    <tr>
        <th>Verde</th>
        <th>Azul</th>
        <th>Amarillo</th>
        <th>Rojo</th>
        <th>Verde parpadeante</th>
    </tr>
    <tr>
        <td>Sin Obstaculo</td>
        <td>Obstaculo Derecha</td>
        <td>Obstaculo Izquierda</td>
        <td>Obstaculo Ambos Lados</td>
        <td>Obstaculo aproximandose</td>
    </tr>
</table>
<p>  
Esto lo implementaremos mediante el siguiente diagrama de SIMULINK, que será un Subsystem que tendrá como entrada un dato binario de 4 bits.
</p>
<h1></h1>
<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/5e31ccb4-4b6c-4003-90c9-43a7af413e64" alt="Módulo Senalizacion">

<br>Colocamos para cada bit un bloque BitWise y un Boolean, los cuales nos permiten examinar y utilizar el valor de ese bit.
En el caso de la intermitencia, colocamos un bloque Switch para diferenciar los casos de Intermitencia (tren de pulsos) o Estable (bloque constante).

El video demostrativo de la señalización led de los obstáculos es el siguiente:

[![Video demostratvo Salir de clase con obstáculos](https://img.youtube.com/vi/zqo0bPWz1SM/0.jpg)](https://www.youtube.com/watch?v=zqo0bPWz1SM)

Este modelo se incluirá en los demás en forma de subsustema:

 <img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/cc004879-1fb3-482c-a949-3d1242f1a82d" alt="Módulo Senalizacion">

### Motores

Para el modelado de los motores se han creado dos módulos, uno para cada rueda. El diagrama utilizado es el siguiente:

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/2c0d6d2e-4e8e-4f5f-a0fa-08b1ba6b4bdf" alt="Modulo MotorsG31">

Cada uno de los circuitos cuenta con tres digital output: uno para ir hacia delante, otro que va hacia detrás y un enable que lo habilita.


### Controlador reactivo

El siguiente segmento presenta el desarrollo de un nuevo programa destinado a capacitar al robot Piero para detectar y evitar obstáculos mediante el uso de los sensores ubicados en la parte delantera. El programa actúa sobre los motores responsables del movimiento de las ruedas para modificar la dirección del robot y sortear obstáculos de manera efectiva.

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/db7bfaa5-7404-4fde-829f-861235db5b0f" alt="Modelo Evita obstáculos">


La implementación de este programa se basa en tres modelos trabajados previamente: el Modelado de Motores, el Modelado de Sensores y el Modelado de Señalización. Estos modelos proporcionan la base necesaria para que el Piero pueda reconocer obstáculos a través de sus sensores y tomar decisiones en tiempo real para evitar colisiones con objetos y paredes.

Este es un video demostrativo de el Piero evitando los obstáculos y con la señalización correspondiente:

[![Video demostratvo Salir de clase con obstáculos](https://img.youtube.com/vi/VB6QkytTeBs/0.jpg)](https://www.youtube.com/watch?v=VB6QkytTeBs)

### Encoders de los motores

Los motores de nuestro Piero cuentan con encoders que nos permiten medir la velocidad de giro del motor. Para ello primero debemos crear un bloque S-FunctionBuilder con la configuración que nos dice el fabricante y, sobre todo, asegurarnos de que los pines de los encoders izquierdo y derecho quedan declarados.

La primera ganancia es simplemente un ajuste para que los dos encoders midan lo mismo. La segunda ganancia realiza un cambio de unidades, multiplicando por "pi", por el radio de la rueda y dividido por el número de pulsos que nos da el encoder al dar una vuelta completa a la rueda. De esta manera conseguimos expresar dicha medida en metros. Por último se deriva la medida de la posición para obtener la velocidad.

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/8f24cb93-f026-4d16-a5a4-f16e8a644dac" alt="Modulo MotorsG31">

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/01548b05-ef15-4d31-b643-52391af77809" alt="Modulo MotorsG31">



#### Calibración de los encoders

La calibración de los encoders se ha realizado en dos etapas:

 - Se han medido el número de interrupciones que se detectan en el motor al darle 10 vueltas completas a las ruedas y se ha dividido entre 10 para obtener el número de interrupciones por vuelta. Así obtenemos una media de las interrupciones por vuelta en lugar de medir sólo una vuelta puesto que conseguiremos un valor más real.

 - Se han realizado numerosas pruebas hasta conseguir que el robot vaya en línea recta y recorra la distancia exacta que le hemos indicado. Para ello, se modifican ligeramente las ganancias del número de interrupciones que se lee de cada rueda hasta conseguir una trayectoria lo más recta posible. Además para conseguir la distancia exacta se puede retocar (muy mínimamente) el número de interrupciones por vuelta. Esto se puede observar en las dós imágenes superiores. En la primera de ellas ya se ha ajustado los valores de las ganancias de cada rueda para que vaya en linea recta, sin embargo la distancia que recorre no es del todo precisa. Por eso se hace un modelo de prueba como el de la segunda imagen en el que el robot recorre la distancia de 10 baldosas de la clase del laboratorio que corresponde a $4,1 m$. Haciendo varias pruebas se queda ajustado hasta obtener un valor de 1496 interrupciones por vuelta.

Podemos ver el resultado de la calibración en el siguiente video:

[![Video demostratvo Calibración encoders](https://img.youtube.com/vi/kBWgP7cRCLU/0.jpg)](https://www.youtube.com/watch?v=kBWgP7cRCLU)



### Control en Bucle Abierto

Necesitamos que nuestro piero sea capaza de seguir una referencia de velocidad en cada una de las ruedas. Para ello se diseña un modelo de control en bucle abierto como el siguiente:

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/e4197d47-ec75-4cca-a0d9-35212e16a6e5)

Su comportamiento es el que se espera y que analizamos a continuación:

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/a89c9a65-3a23-4c17-8709-e49605b1bcda)

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/af48b379-8bd1-42d8-a2c0-c6eb0bfa90c6)

Como se ovserva en la primera fotografía, la velocidad de las ruedas aumenta hasta conseguir el valor de la referencia y, si sufre perturbaciones, vuelve hasta ese valor. En la segunda captura se muestran dos perturbaciones de la rueda derecha y una de la rueda izquierda.

Un pequeño video demostrativo del piero con el control en bucle abierto nos ilustra como no corrrige la trayectoria si no la velodidad de la rueda:

[![Video demostratvo ControlBA](https://img.youtube.com/vi/OU3vdd7K3cA/0.jpg)](https://www.youtube.com/watch?v=OU3vdd7K3cA)

Como cabe de esperar, el piero andará en linea recta a $2 m/s$ y no reaccionará a las perturbaciones corrigiendo la trayectoria sino que volverá a la velocidad establecida en la referencia.

En este modelo podemos ver dos subsistemas:

#### ControladorBA
#### Calibracion de los motores
Es necesario comprobar cómo se comportan nuestros motores según la tensión de alimentación que les llega, por eso hemos realizado un sencillo test en el que aumentamos y disminuimos gradualmente la tensión y reflejamos el movimiento de las ruedas en una gráfica.

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/2dee992c-61a0-4afb-aea9-4d6a189a0a1d" alt="">
La señal de referencia en este caso es una rampa ascendente y descendente. Al simular obtenemos el siguiente resultado:

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/c74d9f3f-710c-42cb-bb8a-e74b358812c0" alt="">

Como podemos observar, exite un amplio rango de valores de tensión en los que no se produce movimiento en los motores. Este rango es mayor para el arranque que para la parada.

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/ef5752fc-e72f-4e75-bed5-873314410e70" alt="">

Estos datos se almacenarán en una serie de archivos:


![image-1](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/d84d853e-8eda-47d1-8078-085c99c2e39f)

De estos datos, obtendremos las Look-Up Table

![image-2](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/1fa9ce01-8a78-47a9-9b59-d0d8f7b1cd59)


Mostramos un pequeño video demostrativo de como se han calibrado los motores en el que se observa también la zona muerta de los mismos:

[![Video demostratvo calibración de motores y zona muerta](https://img.youtube.com/vi/Tgh0nENfXSM/0.jpg)](https://www.youtube.com/watch?v=Tgh0nENfXSM)


#### Piero

Este subsistema se volverá a utilizar en cada uno de los modelos ya que se encarga de decidir si se simulará el modelo del piero o se enviará el control de PWM a los motores tomarán los valores leidos por los encoders. 
Esto se hace con un "Variador de fuente" que elige entre el piero real o Hardware (si se está monitoreando en tiempo real con el piero conectado al equipo) o bien con el modelo del comportamiento de nuestros motores.

Este modelo de comportamiento se obtiene de la siguiente manera:

Con el Piero conectado, creamos una señal de pulsos mediante signal builder y la simulamos, de manera que el robot realiza las acciones de arranque y parada varias veces. Esta gráfica la almacenamos en una tabla de datos para cada rueda. 

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/fbcb6a5d-9e75-4a36-8cba-b464e431baff" alt="">


<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/b1c0e7c6-49f9-4cb7-a34a-e6dc808d03f8" alt="">

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/c09b0444-f086-4a47-8509-42cbd664a6d0)

Obtenidos estos datos, los cargamos en "System Identification", un software que te permite analizar las funciones y elaborar funciones de transferencia ajustadas a nuestros datos.

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/ea677cfa-8091-4b7f-a4a9-48cacf15adf3" alt="">


Una vez aquí, calculamos diferentes funciones de transferencia, en función del número de polos y ceros

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/861486c9-0ebd-4122-9b92-3a98ac148c49" alt="">

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/50cea3ef-ebd2-48eb-921e-d40a8652eff3" alt="">

Como vemos, aquí se representan las gráficas elegidas, en base a lo bien que se ajustan con con el modelo de entrada.
Analizando los datos obtenidos llegamos a la siguiente conclusión:

La que mejor se ajusta, es la de dos polos y un cero. Podríamos haber elegido esta pero el resultado sería muy sensible a alteraciones. Nosotros queremos un sistema estable y gradual, que no cambie bruscamente, por eso elegiremos la TFi10, de un polo. Esta nos dará buenos resultados y como observaremos más adelante en los videos, tenemos un control estable.


### Control en Bucle Cerrado

Para el control de la velocidad en el bucle cerrado haremos algo parecido pero, por supuesto cerrando el bucle.

El modelo que usaremos para llevar a cabo este comportamiento será el siguiente:

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/ae0872d5-3f0d-410d-9d9f-f5233ce47bba)

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/01548b05-ef15-4d31-b643-52391af77809" alt="Modulo MotorsG31">


En este caso, el piero andará en linea recta a $2 m/s$ pero sí reaccionará a las perturbaciones corrigiendo la trayectoria y volverá a la velocidad lineal del robot establecida en la referencia ya que acumula el posible error en cada rueda.

Así, probando los resultados, vemos que si lo ejecutamos y nos oponemos al movimiento de una rueda, el PID hace que se recupere y continúe en la dirección que iba.


<img width="830" alt="Captura de pantalla 2024-01-11 a las 12 33 06" src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/9d158c56-cb4a-4ebf-be3a-267c519f9953">



En el siguiente vídeo se ilustra este funcionamiento

[![Video demostratvo ControlBC](https://img.youtube.com/vi/-JRCHIIsw-Q/0.jpg)](https://www.youtube.com/watch?v=-JRCHIIsw-Q)

Los subsistemas que se utilizan en este caso son el mismo que anteriormente para el modelo del piero y el controlador en bucle cerrrado:

#### ControladorBC

El controlador en este caso lo haremos con un PID para cada rueda en lugar de las look-up tables.


<img width="1329" alt="Captura de pantalla 2024-01-11 a las 12 38 49" src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/44897250-a131-4083-9d43-cc6bf0a8cdb4">


Utilizo el PID tunner para establecer un tiempo de establecimiento de $1 segundo$ aproximadamente ya que así será suficientemente rápido y el tiempo de subida puede ser del orden de medio segundo, la sobreoscilación será $0%$. Hago lo mismo en los dos PID.


<img width="1110" alt="Captura de pantalla 2024-01-11 a las 12 40 32" src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/b4191440-04fd-46bd-9f76-4999e9003c8d">


Una vez se ha probado el modelo de forma experimental y con cambios en la orientación, hemos observado que el controlador tenía cierta sobreoscilación al intentar alcanzar una trayectoria dada. Por tanto se ha vuelto a ajustar, con el PID tunner, reduciendo un poco la ganancia derivativa entre otras cosas y se concluye usando el controlador PID con los parámetros que aparecen en la siguiente captura para ambas ruedas puesto que los resultados son muy buenos.

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/213c37bc-da4f-4f29-9f39-71cbaf65a7fc)


### Cinemática del Piero

A continuación se describe el modelo de la cinemática a implementar en el Piero DIY. Será el que aparece en la siguiente imagen y se describe a continuación:

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/8c8f249f-d5ca-49ed-9fab-76d8c7ced6d5)

Como entrada, en el esquema se están metiendo 2 constantes que son la velocidad lineal en $m/s$ y la velocidad angular en $rad/s$.
Esto es lo que se trata de lograr con este modelo: conseguir que velocidades lineales y angulares sean interpretadas y reproducidas en nuestro piero que sólo entiende de velocidad de las ruedas por separado

Para lograr esto, tendremos que aplicar un modelo cinematico tanto antes como despues del control de velocidad de las ruedas.

Por tanto, los subsistemas que se han utilizado en este caso son:

#### PieroCV
Se trata de un control de velocidad como el que ya hemos hemos implementado anteriormente, usando el bucle cerrado para poder reaccionar ante perturbaciones.
El subsistema es:
![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/0e6e9f09-4c8f-4698-9a6a-d80b247cbca2)

Y toma la referencia de velocidad de la rueda izquierda y derecha para realizar el control.

#### MCI: Modelo Cinemático Inverso
Antes del control le aplicaremos el jacobiano inverso para convertir la velocidad cartesiana local en la velocidad de avance de las ruedas.
![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/a890f444-3b41-4a40-b2cd-9183587718e0)

#### MCD: Modelo Cinemático Directo
Después del control le aplicaremos un modelo cinemático con el jacobiano directo para convertir la velocidad de las ruedas en velocidad cartesiana local.
![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/5ed33e1e-624c-4c96-9f86-0ef2fc2e2b96)

Nota: Para la matriz de los jacobianos necesitamos un parámetro del piero, la distancia entre los ejes de las ruedas que, medida manualmente, establecemos que es $d = 0.22 m$

#### Odometría
Por último, calculamos la odometría de tal forma que, por ejemplo para la rotación de un ángulo $\alpha$ sobre el eje $Z$ se hará:

$$\dot{X} = V_x \cdot cos\left(\alpha\right) - V_y \cdot sen\left(\alpha\right)$$

$$\dot{Y} = V_x \cdot sen\left(\alpha\right) - V_y \cdot cos\left(\alpha\right)$$


Y nos quedaría algo así:

<img width="874" alt="Captura de pantalla 2024-01-11 a las 12 41 13" src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/c2776407-95d7-4846-96fb-2a8994a67ee4">

#### Control del modelo (Simulación o Hardware)

Si ponemos como constantes de entrada:
  - Velocidad lineal: $0.2 m/s$
  - Velocidad angular: $\frac{\pi}{5} rad/s$

Y hacemos la simulación (durante unos 5 segundos), monitoreando el robot real, obtenemos lo que esperamos, el robot anda hacia adelante y gira a la izquierda, describiendo la siguiente trayectoria con la odometría:
![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/50d40c8c-64dd-4f17-9ef3-ba5dc9d295b8)

También mostramos un video del comportamiento en el robot real

[![Video demostratvo PieroCinematica](https://img.youtube.com/vi/YsWtWxGMNfY/0.jpg)](https://www.youtube.com/watch?v=YsWtWxGMNfY)

### Control de orientación

Por último, para conseguir que nuestro piero sea completamente controlable, tenemos que ser capaces de controlar la orientación.

Añadiremos, entonces, un control de orientación para que, en lugar de tener la velocidad lineal y angular como constantes, la velocidad angular esté controlada mediante un controlador (PID) que actua sobre el error en la orientación medida del modelo real del Piero. El modelo sería similar al anterior pero con este controlador para lograr el cambio de orientación

<img width="1438" alt="Captura de pantalla 2024-01-11 a las 12 42 05" src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/85fe43db-f5d6-417c-95a9-e9f9e9ea928a">

Es importante que el PID tenga límites en la saturación. En este caso le hemos puesto el límite superior en 3 y el inferior en -3. Estos valores dependen de los motores y de la velocidad máxima que querremos. En este caso se limitará a unos 0.3 m/s

Por ejemplo, si ejecutamos la simulación en el piero y monitoreamos un cambio de orientación de $0$ a $\frac{\pi}{2} rad$, observamos que el controlador actúa hasta que se ha logrado establecer el ángulo en $90^o$.

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/9b61556a-605e-4908-90f5-8be980611a3c)

Teniendo este modelo, vamos a ver si podemos corregir algo del posible error que se puede cometer por la medida de la distancia entre ejes de forma manual (que establecimos previamente en $d = 0.22 m$).

Para ello, haremos que el Piero de 10 vueltas sobre sí mismo (para ver el error acumulado ya que, en una sola vuelta, no sería suficiente error) poniendo la velocidad lineal a $v = 0 m/s$ y lel error en orientación a $20\pi$ que equivaldría a 10 vueltas completas.

Si en la realidad da menos de 10 vueltas, hay que bajar la d porque el sistema cree que ha recorrido más espacio cuando no lo ha hecho y si se para antes de tiempo, hay que subir ligeramente la d
En nuestro caso, como se observa en el siguiente video se ha quedado corto, le ha faltado más de una vuelta, así que habría que aumetar el valor de la distancia entre ruedas. 

[![Video demostratvo 10 Vueltas Incompletas](https://img.youtube.com/vi/_kR8HMQxs_Y/0.jpg)](https://www.youtube.com/watch?v=_kR8HMQxs_Y)


Tras probar varias veces, acabamos dando las 10 vueltas exactas (como se aprecia en el vídeo y finalmente el valor que tomamos es de $d = 0.2275 m$

[![Video demostratvo 10 Vueltas Completas](https://img.youtube.com/vi/Sdw2mhJyUDc/0.jpg)](https://www.youtube.com/watch?v=Sdw2mhJyUDc)


Vemos entonces, que se ha corregido el error en la orientación haciendo el mismo giro de 90 grados.

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/fc4331ba-b43a-4ac8-94e9-22b0e5fccfe9)
 


## Modelos para salir de clase
A continuación se detallarán una serie de modelos que proporcionarán al Piero las actuaciones necesarias para conseguir seguir una trayectoria predefinida. Han sido creados para comprobar la versatilidad que ofrece SIMULINK para realizar dicha tarea y así poder comparar para ver qué modelo se adapta mejor.

### Salir de clase con Signal Builder

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/1b6e65d1-6949-432e-a8db-7e9187f3466e" alt="SignalBuilder">

Este modelo es el primero que se implementó, y el más rudimentario. 
Directamente a través de un generador de señales (Signal Builder), se crea una para la velocidad lineal y otra para la angular. Esta gráfica representa el valor de salida que estará enviando a lo largo del tiempo.
Es muy complicado definir una trayectoria precisa mediante este método, ya que habrá que calcular para cada movimiento, el tiempo ddurante el que se tiene que aplicar cada comando para recorrer la distancia o girar el ángulo deseado.

### Salir de clase con Matlab Function


<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/050cedc0-b910-4944-a2e1-df82eafc195c" alt="waypoints">

El modelo Salir de clase con Matlaf Function hace uso del bloque Matlab function, al que se le ha programado un pequeño algoritmo de Pure Pursuit.

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/e253f826-9fc4-4400-aa83-c610d824c052" alt="MF">

Como podemos ver en esta imagen ampliada, la trayectoria pasa directamente a la variable "camino", la posición x e y vienen de la odometría, y la i, representa la iteración por donde va respecto a la trayectoria.


<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/4e4621c6-b4a8-4e7d-8144-92bdf4e2b5fb" alt="MF">

Este bloque tomaraá como entrada la matriz de puntos predefinida y la posición X,Y del robot. Como salida, se encarga de proporcionar valores de velocidad lineal y angular adecuados para seguir la trayectoria.

Hemos hecho un par de intentos y no funciona mal pero hemos obtenido algunos resultados mejores usando el bloque de Pure Pursuit. No obstante, se adjunta un video de prueba con resultasdos muy razonables:

[![Video demostratvo Salir de clase usando Matlab Function](https://img.youtube.com/vi/nUrU1EKVeNY/0.jpg)](https://www.youtube.com/watch?v=nUrU1EKVeNY)

### Salir de clase con Waypoints

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/b4c160ad-f425-46e8-9102-0a1d6c8ce836" alt="waypoints">
El modelo de Salir de clase con Waypoints hace uso del bloque Pure Pursuit. Este algoritmo es muy utilizados en sistemas de conducción autónoma, donde se proporciona al robot comandos de velocidad lineal y angular para perseguir una trayectoria predefinida con puntos x e y.

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/5bafc313-3558-472d-afe9-73bbd95c5f0e" alt="XY">

Como podemos observar en la simulación, el modelo es preciso.

### Salir de clase con StateFlow

El objetivo de este modelo es que el PIERO salga de clase por sí mismo a partir de unas consignas de velocidad lineal y velocidad angular deseada, en este caso la principal diferencia respecto al resto de salir de clase es el uso de la herramienta State Flow.

Stateflow es una herramienta de modelado de sistemas dinámicos desarrollada por MathWorks. Permite al usuario diseñar, simular y analizar sistemas de tiempo discreto y continuo mediante el uso de diagramas de estados y transiciones, funciones y tablas de eventos. Es utilizado principalmente en aplicaciones de control, automatización, procesamiento de señales y análisis de sistemas complejos. Stateflow se integra con otros productos de MathWorks, como Simulink, para proporcionar una solución completa de modelado y simulación.

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/ff36d2b6-d3ed-40da-9ab6-f428130c4653" alt="waypoints">

A la entrada del diagrama tenemos la odometría de nuestro robot; y, sabiendo su posición, podemos enviar comandos de velocidad para cubrir distancias específicas tanto lineales como angulares. De esta manera programamos la trayectoria completa deseada.

  

Todos los videos de salir de clase con los diferentes métodos devuelven resultados muy similares pero, después de probarlos todos y ajustarlos para que funcionen lo mejor posible, el que mejor resultados nos ha dado es en el que mayor control de la trayectoria y, por tanto, mejores resultados nos ha dado ha sido en el que usamos el bloque "Pure Pursuit" de la librería de Navigation Toolbox. 
El vídeo del funcionamiento de este modelo preparado para que el piero salga de clase (sin evitar obstáculos), es el siguiente:

[![Video demostratvo Salir de clase sin obstáculos](https://img.youtube.com/vi/2jOPRIdVmmE/0.jpg)](https://www.youtube.com/watch?v=2jOPRIdVmmE)

### Salir de clase con Waypoints y evitando obstaculos

El objetivo de este proyecto es permitir que el robot, denominado PIERO, salga de clase de manera autónoma utilizando consignas de velocidad lineal y angular deseadas. Este proceso se llevará a cabo mediante una función de Matlab que implementa el modelo PurePursuit. Además, se busca incorporar la capacidad de esquivar obstáculos, y para ello se ha elegido utilizar la herramienta State Flow.

Es importante destacar que tanto Matlab como State Flow han sido empleados en modelos anteriores, por lo que se comprende su funcionamiento y modo de operación. La diferencia principal radica en la integración de la información proporcionada por cada herramienta, así como en la implementación específica para evitar obstáculos utilizando State Flow.

El modelo de State Flow seleccionado para la tarea de esquivar obstáculos será crucial en la autonomía de PIERO, permitiéndole tomar decisiones dinámicas en tiempo real para sortear cualquier impedimento que pueda surgir en su camino.

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/a7dfca92-cdbe-4b5e-b8e5-088e661849ef" alt="waypoints">

En esta imagen se implementa el control 

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/a9048b6c-49a8-46a2-856e-9935f7bb182f" alt="waypoints">
El bloque Sonars, nos da las medidas de los sensores, y según esta, se señalizará con el bloque de señalización. Por último, se realizará el control reactivo mediante el StateFlow.
El otro circuito que se muestra, es el propio modelo de movimiento del Piero, controlado esta vez por el modulo pure pursuit, con la trayectoria predefinida en la matriz.


Al simular el Piero con la trayectoria predefinida obtenemos la siguiente gráfica:
<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/607454fc-9f49-40c1-8b2e-258069078baf" alt="waypoints">
Como se puede apreciar en la gráfica, el control implementado es bastante preciso y nos permite realizar trayectorias específicas esquivando obstáculos con gran habilidad. Es por eso que el método implementado en el Piero será este.

[![Video demostratvo Salir de clase con obstáculos](https://img.youtube.com/vi/SUVn5_DVqa4/0.jpg)](https://www.youtube.com/watch?v=SUVn5_DVqa4)

## Parte extra: Implementación de una video cámara y de un mando para controlar la orientación de la dicha cámara y la posición del Piero

### Introducción

La parte extra para nuestro proyecto consiste principalmente en tres implementaciones:

- Uso de una cámara para poder ver lo que ve el robot el tiempo real. Además, poder controlar la posición de la cámara para orientarla en 360 grados, sacar fotos, guardarlas en una base de datos para poder recuperarlas posteriormente y usar el flash.
  
- Uso de una pasarela Wifi para el Arduino Mega 2560, y así poder mandarle comandos de velocidad y por tanto, de posición de manera manual.

- Uso de un mando para controlar tanto la orientación de la cámara como los comandos emitidos al Piero.

Antes de pasar a los detalles, se muestran dos videos del funcionamiento del mismo. En el primero la cámara está siendo controlada mientras el piero explora la zona y en el segundo se controla la cámara desde el propio mando a distancia.

[![Video demostratvo Salir de clase con obstáculos](https://img.youtube.com/vi/6Vd62COOqGI/0.jpg)](https://www.youtube.com/watch?v=6Vd62COOqGI)

[![Video demostratvo Salir de clase con obstáculos](https://img.youtube.com/vi/HZeDFFgzWQ8/0.jpg)](https://www.youtube.com/watch?v=HZeDFFgzWQ8)

  
### Programas utilizados

Para el desarrollo de esta implementación haremos uso de dos entornos dos entornos de programación:

- Arduino IDE: con esta herramienta, programaremos todos los microncontroladores usados.
  
- NodeRed: con esta herramienta, prograremos la lógica del sistema de control con el que los dispositivos se interconectaran entre sí. La conexión entre ellos y con el propio servidor en el que está corriendo NodeRed (en este caso, uno de nuestros ordenadores) principalmente se realizará mediante MQTT, haciendo uso de distintos topics para el envío y recepción de datos.

### Materiales usados
A continuación, se detallan algunas características relevantes de todos los materiales usados en esta ampliación del proyecto.

- ESP32 Wrover Cam: La ESP32 WROVER-CAM, basada en el chip ESP32, destaca por su diseño compacto y versátil, integrando conectividad Wi-Fi y Bluetooth junto con una cámara que emplea el sensor OV-2640. Este módulo es especialmente adecuado para proyectos de IoT, video vigilancia, captura de imágenes y transmisión en tiempo real, gracias a su potente procesador dual-core Xtensa LX6 que garantiza un rendimiento eficiente.Uno de los puntos destacados de este módulo son sus GPIOs multipropósito, que ofrecen flexibilidad en el diseño y la implementación de proyectos. Estos pines pueden configurarse para diversas funciones, como entrada analógica, salida digital o comunicación serial, lo que amplía las posibilidades de integración con otros dispositivos y sensores. Este módulo será nuestra cámara para el robot.

<p align="center">
  <img src="/fotos/image-1.png" alt="Descripción de la /fotos/imagen">
</p>
  
- ESP32 Wroom 32: La ESP32 WROOM-32, basada en el chip ESP32, es un módulo compacto y versátil que incorpora conectividad Wi-Fi y Bluetooth, siendo una opción ideal para proyectos de IoT, automatización, y aplicaciones inalámbricas. Equipada con un procesador dual-core Xtensa LX6, ofrece un rendimiento eficiente para tareas complejas. Los GPIOs versátiles proporcionan flexibilidad en el diseño, permitiendo configurar los pines para diversas funciones, como entrada/salida digital, comunicación serial, o lectura analógica. Esto facilita la integración con sensores y otros componentes externos, adaptándose a diferentes requisitos de proyectos. La capacidad para ejecutar aplicaciones web directamente en el módulo facilita la visualización remota de datos y la configuración a través de interfaces basadas en navegador. Este módulo será el encargado de darle una unidad de procesamiento a nuestro mando.

<p align="center">
  <img src="/fotos/image-2.png" alt="Descripción de la /fotos/imagen">
</p>
  
- ESP8266 NodeMCU ESP-12E: esta es una placa de desarrollo versátil que cuenta con 17 pines GPIO digitales, permitiendo la implementación de PWM de 10 bits en los pines GPIO0 al GPIO15. Algunos GPIO, como el GPIO16, tienen usos específicos, como despertar la placa del modo de suspensión profunda. Sin embargo, se recomienda evitar el uso de ciertos pines, como GPIO6 al GPIO11, que no son accesibles a través de la placa de desarrollo (excepto el 9 y el 10). Además, se destaca la presencia de pines dedicados para SPI y la conversión analógica a digital (ADC0) en A0 con un rango de entrada de 0 a 3.3V. Este módulo será el que haga de pasarela WIFI a nuestra Arduino Mega del Piero.
  
<p align="center">
  <img src="/fotos/image-3.png" alt="Descripción de la /fotos/imagen">
</p>

- Arduino Nano: es una placa de desarrollo compacta basada en microcontroladores de la familia ATmega, fabricada por Arduino. Se destaca por su tamaño reducido y su capacidad para realizar diversas tareas de programación y control. El Nano cuenta con entradas y salidas digitales y analógicas, puertos de comunicación, etc. Este módulo será el encargado de controlar los movimientos del motor paso a paso, descrito en el siguiente punto.
  
<p align="center">
  <img src="/fotos/image-4.png" alt="Descripción de la /fotos/imagen">
</p>

- Motor paso a paso 28BYJ-48: este motor unipolar, aunque no es demasiado potente ni excesivamente rápido, cumple con los requisitos necesarios para el desarrollo de su aplicación en este proyecto. Se trata de un motor de 4 Fases con una resistencia de 50 Ω y un par motor de 34 Newton / metro más o menos 0,34 Kg por cm. Consume unos 55 mA y es de 8 pasos por vuelta por lo que, para completar un giro completo de 360º, necesita 512 impulsos. Este motor será el encargado de darle el movimiento a la cámara. Debido a que un motor paso a paso consume una corriente elevada y puede necesitar una tensión mayor a los 5 VDC de nuestro Arduino, no podemos realizar una conexión directa entre este y la placa Arduino. Se requiere un manejador (driver) o interface para brindar al motor la tensión y la corriente necesarias, por eso utilizamos el siguiente módulo.

<p align="center">
  <img src="/fotos/image-5.png" alt="Descripción de la /fotos/imagen">
</p>
  
- Driver ULN2003A: este módulo cuenta con el controlador ULN2003 que posee una configuración Darlington y se encarga de incrementar el nivel de corriente para suplir la potencia necesaria que solicita el motor paso a paso. permite la adaptación de cualquier motor paso a paso cuando se conecta directamente. Posee cinco lí­neas de conexión para el motor, además de cuatro fases.
  
<p align="center">
  <img src="/fotos/image-6.png" alt="Descripción de la /fotos/imagen">
</p>

- Sensor de final de carrera: es un dispositivo que conmuta internamente sus conexiones al recibir una pulsación mecánica, haciendo que la corriente de la base pase a circular por el pin NO (Normally Open) en vez de por el pin NC (Normally Closed). En nuestro caso, haremos uso de este dispositivo para detectar cuando el motor que controla la posición de la cámara llega al origen del recorrido y realizar así su calibración.

<p align="center">
  <img src="/fotos/image-8.png" alt="Descripción de la /fotos/imagen">
</p>

- Convertidor de tensión Buck Mini-360-DC: este es un dispositivo compacto y eficiente diseñado para convertir tensiones de entrada mayores a tensiones de salida más bajas de manera controlada. Su tensión de salida se ajusta mediante el potenciómetro integrado. Esto permite adaptar la salida a las necesidades específicas de un proyecto o dispositivo.  Este tipo de convertidor es comúnmente utilizado en aplicaciones electrónicas para alimentar dispositivos que requieren una tensión de alimentación menor que la disponible. En nuestro caso, lo usaremos para adaptar la salida de 12 Voltios de un cojunto de pilas y así poder alimentar dispositivos como el mando que controle la cámara, o el propio ecosistema de la cámara.

<p align="center">
  <img src="/fotos/image-7.png" alt="Descripción de la /fotos/imagen">
</p>

- Pilas: usaremos 3 pilas 3 4 Voltios y 3700 mAh para darle energía a nuestro sistema de la cámara.

<p align="center">
  <img src="/fotos/image-10.png" alt="Descripción de la /fotos/imagen">
</p>

- Diodos led: se usarán 3 diodos led de colores rojo, verde y blanco para tener indicadores de conexión WIFI (rojo sin conexión, verde con conexión) y para tener un flash para la cámara (led blanco). Además, para alimentar estos diodos haremos uso de resistencias de 220 Ω y así limitar la corriente que pase por ellos.

<p align="center">
  <img src="/fotos/image-9.png" alt="Descripción de la /fotos/imagen">
</p>

- Módulos de joystick: estos módulos constan de dos potenciómetros en perpenticular que leen la posición del joystick en función de la corriente que pase por ellos. Además, cuentan con un pulsador para hacer la función de click.

<p align="center">
  <img src="/fotos/image-14.png" alt="Descripción de la /fotos/imagen">
</p>

### Implementación del mando

El mando que vamos a usar consta de una ESP32 Wroom-32 que leerá los datos de posición de dos joysticks conectados a ella. Cada uno de estos joysticks será la herramienta con la que nos comunicaremos para construir comandos para la cámara y para el Piero. 

Los comandos realizados con el joystick para la cámara seguirán la siguiente lógica:

- Desplizamiento vertical positivo: Activar/desactiva el flash de la cámara.
- Desplazamiento vertical negativo: Centrar la cámara en su orientación de origen.
- Desplazamiento horizontal positivo: Girar la cámara hacia la derecha.
- Desplazamiento horizontal negativo: Girar la cámara hacia la izquierda.
- Click: Hacer una foto.

Los comandos realizados con el joystick para el piero seguirán la siguiente lógica:

- Desplizamiento vertical positivo: Velocidad lineal del robot positiva, magnitud en función de la posición del joystick.
- Desplazamiento vertical negativo: Velocidad lineal del robot negativa, magnitud en función de la posición del joystick.
- Desplazamiento horizontal positivo: Velocidad angular del robot positiva, magnitud en función de la posición del joystick.
- Desplazamiento horizontal negativo: Velocidad angular del robot negativa, magnitud en función de la posición del joystick.
- Click: Cambiar el modo de funcionamiento, para pasar al modo de funcionamiento de navegación reactiva o al modo de navegación manual controlado mediante el mando.

Además, todas las funciones del mando podrán ser igualmente accesibles tanto desde la Dashboard de Nodered como desde un bot de Telegram que hemos programado para dicha tarea.

#### Diseño del circuito

A continuación, aparece el esquema del circuito diseñado para el mando.

<p align="center">
  <img src="/fotos/image.png" alt="Descripción de la /fotos/imagen">
</p>

El montaje real del prototipo queda así: 

<p align="center">
  <img src="/fotos/image-13.png" alt="Descripción de la /fotos/imagen">
</p>

#### Programación y lógica de funcionamiento

Los joysticks son dispositivos analógicos. Debido a la naturaleza de estos dispositivos, los pines de posición horizontal y vertical de cada uno tienen que ir conectados a pines que estén conectados al conversor analógico-digital de la placa, para poder hacer así una lectura de la información. Este es el motivo principal por el que se ha usado una ESP32 en lugar de una ESP8266 para el mando, ya que la ESP8266 cuenta con un único pin conectado a un conversor analógico-digital integrado, claramente insuficiente para esta tarea. 

Otro de los problemas que encontramos es que, aunque la ESP32 tenga pines analógicos más que suficientes para leer la información de los dos joysticks, el conversor analógico-digital que incorpora no es totalmente lineal, sino que tiene el comportamiento reflejado en la siguiente /fotos/imagen.

<p align="center">
  <img src="/fotos/image-15.png" alt="Descripción de la /fotos/imagen">
</p>

Como se puede observar, a partir de un voltaje de entrada aproximado de 3,1 Voltios, el conversor se satura y devuelve un valor digital máximo de aproximadamente 4095. De igual forma ocurre con el límite inferior del rango de tensión, ya que hasta que no se superan los 0,1 con Voltios de tensión de entrada, el conversor devolverá un valor digital de prácticamente 0. 

Además, la tanto la calidad de la fabricación de los potenciómetros de los joysticks como la propia calidad de lectura del conversor analógico-digital de la placa crea un ruido bastante notable en los resultados, arrojando una lectura muy inestable e imprecisa. Esto crea un desafío a la hora de convertir las señales analógicas de los joysticks en comandos de movimiento. 

La solución que le hemos dado a este problema es el acotamiento de la tensión que recibe el conversor en 7 niveles, por lo que, si antes se contaba con una sensibilidad de lectura entre 0 y 4095, ahora la información de los joysticks se ha codificado en valores que van desde -3 hasta 3 para los dos ejes de lectura. Con ello, se reduce el ruido producido en la lectura haciéndolo imperceptible, se eliminan los movimientos fantasmas, y se ofrece una sensibilidad para los comandos más que suficiente para la aplicación de este proyecto.

A continuación, se adjunta el programa contenido en la ESP32 Wroom 32.

Primero se declaran todas las librerías, topics y variables necesarias:
```arduino
#include <ArduinoJson.h>
#include <WiFi.h>
#include <PubSubClient.h>

String ssid = "MiFibra-9B77";
String password = "oRfwyF6X";
String mqtt_server = "iot.ac.uma.es"; 
String mqtt_user = "II10";
String mqtt_pass = "wD9IYehI";
String ID_PLACA = String(ESP.getEfuseMac());
String topicPiero = "II10/ESP"+ID_PLACA+"/mando/piero";
String topicCamara = "II10/ESP"+ID_PLACA+"/mando/camara";
String topic_PUB_conexion = "II10/ESP"+ID_PLACA+"/mando/conexion";
String mensaje_conexion = "{\"mando\":connected}";
String LWT = "{\"mando\":disconnected}";

WiFiClient wClient;
PubSubClient mqtt_client(wClient);
// Pines para los indicadores de conexión
const int pinRojo = 5;
const int pinVerde = 18;
// Pines para los joysticks
const int pinxCamara = 33;
const int pinyCamara = 32;
const int pinButtonCamara = 17;

const int pinxPiero = 34;
const int pinyPiero = 39;
const int pinButtonPiero = 16;

const int rango = 6;

// Tamaño del buffer para mensajes JSON
const size_t bufferSize = 512;

// Variables para almacenar las lecturas
int oldxValueCamara = 0, newxValueCamara = 0;
int oldyValueCamara = 0, newyValueCamara = 0;
int oldButtonCamara = 1, newButtonCamara = 1;

int oldxValuePiero = 0, newxValuePiero = 0;
int oldyValuePiero = 0, newyValuePiero = 0;
int oldButtonPiero = 1, newButtonPiero = 1;
```

Se añaden todas las subfunciones necesarias para el programa. La siguiente, es la encargada de leer los datos de los joysticks. Aquí se acota la tensión de cada potenciómetro del joystick en un valor del -3 al 3, tal y como se explicó anteriormente:

```arduino
size_t leerJoyStick(int pinx, int piny, int pinButton, int &oldx, int &newx, int &oldy, int &newy, int &oldButton, int &newButton) {
  newx = analogRead(pinx);
  newy = analogRead(piny);
  newButton = !digitalRead(pinButton);

  if (newx >= 0) {
    newx = (round((4095 - newx) * rango / 4095) - rango/2);
  } else {
    newx = (round((-4095 + newx) * rango / 4095) - rango/2);
  }

  if (newy >= 0) {
    newy = (round((4095 - newy) * rango / 4095) - rango/2);
  } else {
    newy = (round((-4095 + newy) * rango / 4095) - rango/2);
  }

  if ((newx != oldx) || (newy != oldy) || (newButton != oldButton)) {
    // Actualizamos el valor de las variables antiguas
    oldx = newx;
    oldy = newy;
    oldButton = newButton;
    return true;
  } else {
    return false;
  }
}
```

Se añaden todas las subfunciones necesarias para realizar las conexiones de Wifi y MQTT:

```arduino
//-----------------------------------------------------
void conecta_wifi() {
  Serial.println("Connecting to " + String(ssid));
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  Serial.println();
}
//-----------------------------------------------------
void conecta_mqtt() {// Loop until we're reconnected
  while (!mqtt_client.connected()) {
    Serial.print("Attempting MQTT connection...");// Attempt to connect
    if (mqtt_client.connect(ID_PLACA.c_str(),mqtt_user.c_str(),mqtt_pass.c_str(),topic_PUB_conexion.c_str(),2,false,LWT.c_str())){
      Serial.println(" conectado a broker: " + String(mqtt_server.c_str()));
    } else {
      Serial.println("ERROR:"+ String(mqtt_client.state()) +" reintento en 5s" );
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
```

Setup del programa. Se realizan todas las incializaciones necesarias:

```arduino
void setup() {
  Serial.begin(115200);
  Serial.println("TOPIC: " + topicPiero);
  pinMode(pinButtonCamara, INPUT_PULLUP);
  pinMode(pinButtonPiero, INPUT_PULLUP);
  pinMode(pinVerde,OUTPUT);
  pinMode(pinRojo,OUTPUT);
  digitalWrite(pinVerde,LOW);
  digitalWrite(pinRojo,HIGH);
  conecta_wifi();
  mqtt_client.setServer(mqtt_server.c_str(), 1883);
  mqtt_client.setBufferSize(512); 
  conecta_mqtt();
  Serial.println("Identificador placa: "+ String(ID_PLACA));
  Serial.println("Topic publicacion control Piero: "+ String(topicPiero));
  Serial.println("Topic publicacion control Camara: "+ String(topicCamara));
  StaticJsonDocument<bufferSize> mensajePiero;
  String mensajePieroString;
  mensajePiero["X"] = 0;
  mensajePiero["Y"] = 0;
  mensajePiero["Button"] = 0;
  serializeJson(mensajePiero, mensajePieroString);
  StaticJsonDocument<bufferSize> mensajeCamara;
  String mensajeCamaraString;
  mensajeCamara["X"] = 0;
  mensajeCamara["Y"] = 0;
  mensajeCamara["Button"] = 0;
  serializeJson(mensajeCamara, mensajeCamaraString);
  mqtt_client.publish(topicPiero.c_str(),mensajePieroString.c_str());
  mqtt_client.publish(topicCamara.c_str(),mensajeCamaraString.c_str());
  Serial.println("Termina setup en " +  String(millis()) + " ms");
}
```

Bucle principal del programa. Se comprueba la conexión de la placa y la lectura de los joysticks. En el caso de que la lectura de los joysticks cambie, se envía su nueva posición por MQTT.

```arduino
void loop() {
  static unsigned long ultimo_mensaje=0;
  static unsigned long ahora=0;

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Conexión WiFi perdida. Intentando reconectar...");
    digitalWrite(pinVerde,LOW);
    digitalWrite(pinRojo,HIGH);
    conecta_wifi();
  }else{
    digitalWrite(pinVerde,HIGH);
    digitalWrite(pinRojo,LOW);
  }

  if (!mqtt_client.connected()) {
    conecta_mqtt();
  }
  mqtt_client.loop(); // esta llamada para que la librería recupere el control
  
  ahora = millis();

  if (ahora - ultimo_mensaje >= 100) {
    ultimo_mensaje = ahora;
    if (leerJoyStick(pinxCamara, pinyCamara, pinButtonCamara, oldxValueCamara, newxValueCamara, oldyValueCamara, newyValueCamara, oldButtonCamara, newButtonCamara)){ // mandamos mensaje si cambian los valores leidos
      // Actualizamos el valor del mensaje a mandar
      StaticJsonDocument<bufferSize> mensajeCamara;
      String mensajeCamaraString;
      mensajeCamara["X"] = oldxValueCamara;
      mensajeCamara["Y"] = oldyValueCamara;
      mensajeCamara["Button"] = oldButtonCamara;
      serializeJson(mensajeCamara, mensajeCamaraString);
      Serial.print("Comando de Cámara enviado: ");
      Serial.println(mensajeCamaraString);
      mqtt_client.publish(topicCamara.c_str(),mensajeCamaraString.c_str());
    }

    if (leerJoyStick(pinxPiero, pinyPiero, pinButtonPiero, oldxValuePiero, newxValuePiero, oldyValuePiero, newyValuePiero, oldButtonPiero, newButtonPiero)) { // mandamos mensaje si cambian los valores leidos
      //Actualizamos el valor del mensaje a mandar
      StaticJsonDocument<bufferSize> mensajePiero;
      String mensajePieroString;
      mensajePiero["X"] = oldxValuePiero;
      mensajePiero["Y"] = oldyValuePiero;
      mensajePiero["Button"] = oldButtonPiero;
      serializeJson(mensajePiero, mensajePieroString);
      Serial.print("Comando de Piero enviado: ");
      Serial.println(mensajePieroString);
      mqtt_client.publish(topicPiero.c_str(),mensajePieroString.c_str());
    }
  }
}
```
El código completo puede verse [AQUÍ](/CodigosArduino/Mando_GR31/Mando_GR31.ino)
### Implementación de la cámara y su sistema de movimiento
#### Diseño del circuito

A continuación, aparece el esquema del circuito diseñado para la cámara y su sistema de movimiento.
 
<p align="center">
  <img src="/fotos/image-12.png" alt="Descripción de la /fotos/imagen">
</p>

El montaje real del prototipo queda así: 

<p align="center">
  <img src="/fotos/image-11.png" alt="Descripción de la /fotos/imagen">
</p>

#### Programación y lógica de funcionamiento

En este proyecto, al conectarse a nuestra red la ESP32 Wrover Cam crea un servidor local donde se envía constantemente la /fotos/imagen tomada por su sensor, simulando un vídeo en streaming.

Para saber en qué IP local se encuentra conectada la cámara, esta informa de ello enviando su IP actula por MQTT a NodeRed. Por tanto, la /fotos/imagen de la cámara puede verse en la dirección http://192.168.1.XXX:81/stream.

La toma de fotos de la cámara se realiza mediante un htto request a dicho servidor, haciendo uso del API http://192.168.1.XXX:/capture.

Además, la placa se suscribe a los topics correspondientes para poder recibir los comandos de movimiento de la misma, así como los comandos para controlar el flash.

Sin embargo, la librería que se ha usado para controlar el motor paso a paso hace que cada vez que se quiera hacer girar dicho motor el programa principal quede bloqueado y por tanto "pausando" la /fotos/imagen en directo de la cámara. Para solventar esto, hemos hecho uso del anteriormente mencionado Arduino Nano, que queda conectado a la ESP32 Wrover Cam con dos pines digitales. Dichos pines codifican 4 estados posibles, con el siguiente significado:

| Pin "Left" | Pin "Right" | Significado|
|--------------|--------------|--------------|
| 0    |0   | Detener motor    |
| 0    | 1    | Girar hacia la derecha  |
| 1  | 0   | Girar hacia la izquierda   |
| 1    | 1   | Llevar cámara al origen |

A continuación, se adjunta el programa de Arduino para la ESP32 Wrover Cam.

Primero, se incluyen todas las librerias, variables y pines necesarios:

```arduino
#define CAMERA_MODEL_WROVER_KIT 
#define LED_BUILTIN 2
#define DEBUG_STRING "["+String(__FUNCTION__)+"():"+String(__LINE__)+"] "
#include "esp_camera.h"
#include <WiFi.h>
#include <string>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <Stepper.h>
#include "camera_pins.h"

const int ledVerde = 33;
const int ledRojo = 32;
const int left = 14;
const int rigth = 12;
const int pinflash = 15;

const String ssid = "Iphone de David";
const String password = "12345678";

camera_config_t config;
void startCameraServer();
void config_init();

WiFiClient wClient;
PubSubClient mqtt_client(wClient);
const String mqtt_server = "iot.ac.uma.es";
const String mqtt_user = "II10";
const String mqtt_pass = "wD9IYehI";
const String ID_PLACA = String(ESP.getEfuseMac());
const String ID_PLACA_EMISORA = "36221669107172";
const String topicCamara = "II10/ESP" + ID_PLACA_EMISORA + "/mando/camara";
const String topic_PUB_conexion = "II10/ESP"+ID_PLACA+"/camara/conexion";
const String topic_PUB_flash = "II10/ESP"+ID_PLACA+"/camara/responseFlash";
const String topic_SUB_flash = "II10/ESP"+ID_PLACA+"/camara/requestFlash";
const String topic_PUB_foto = "II10/ESP"+ID_PLACA+"/camara/fotoRutinaria";
const String topic_SUB_tiempo = "II10/ESP"+ID_PLACA+"/camara/tiempo";
const String topic_PUB_ip = "II10/ESP"+ID_PLACA+"/camara/IP";
const String topic_SUB_ip = "II10/ESP"+ID_PLACA+"/camara/IPRequest";
const String mensaje_conexion = "{\"online\":true}";
const String mensajefoto = "{\"foto_rutinaria\":1}";
const String LWT = "{\"online\":false}";


int tiempo_foto = 60; // por defecto, se toma una foto de seguridad cada 60 minutos
```
Se añaden todas las subfunciones necesarias para realizar las conexiones de Wifi y MQTT:

```arduino
void conecta_wifi() {
  Serial.println(DEBUG_STRING+"Conectando a " + ssid);

  WiFi.begin(ssid, password);
  WiFi.setSleep(false);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
    delay(200);
    Serial.print(".");
    digitalWrite(ledRojo,HIGH);
    digitalWrite(ledVerde,LOW);
  }
  digitalWrite(LED_BUILTIN,HIGH);
  Serial.println();
  Serial.println(DEBUG_STRING+"WiFi conectada, dirección IP: " + WiFi.localIP().toString());
}
//-----------------------------------------------------------
void conecta_mqtt() {// Loop until we're reconnected
  while (!mqtt_client.connected()) {
    Serial.print(DEBUG_STRING+"Attempting MQTT connection...");// Attempt to connect
    if (mqtt_client.connect(ID_PLACA.c_str(),mqtt_user.c_str(),mqtt_pass.c_str(),topic_PUB_conexion.c_str(),2,false,LWT.c_str())) {
      Serial.println(" conectado a broker: " + mqtt_server);
        mqtt_client.subscribe(topic_SUB_flash.c_str());  
        mqtt_client.subscribe(topic_SUB_tiempo.c_str()); 
        mqtt_client.subscribe(topicCamara.c_str());
        mqtt_client.subscribe(topic_SUB_ip.c_str());
        mqtt_client.publish(topic_PUB_ip.c_str(), (WiFi.localIP().toString()).c_str());
    } else {
      Serial.println("ERROR:"+ String(mqtt_client.state()) +" reintento en 5s" );
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
```
Subfunción para la gestión de los mensajes recibidos por MQTT. Aquí se le pasa al Arduino Nano la información de los comandos de movimiento de la cámara, se actúa sobre el estado del flash y se manda la IP de la cámara:
```arduino
void procesa_mensaje(char* topic, byte* payload, unsigned int length) { 
  String mensaje=String(std::string((char*) payload,length).c_str());
  Serial.println("Mensaje recibido ["+ String(topic) +"] "+ mensaje);
  if(String(topic)==topic_SUB_tiempo){
    DynamicJsonDocument mensaje_json(50);
    DeserializationError error = deserializeJson(mensaje_json,mensaje);
    if(not error){
      tiempo_foto = mensaje_json["tiempo"];
      Serial.println(DEBUG_STRING + "Actualizando tiempo de foto de seguridad a "+tiempo_foto+" minutos.");
    }
  }else if(String(topic)==topic_SUB_ip){
    mqtt_client.publish(topic_PUB_ip.c_str(), (WiFi.localIP().toString()).c_str());
  }else if(String(topic)==topic_SUB_flash){
    DynamicJsonDocument mensaje_json(50);
    DeserializationError error = deserializeJson(mensaje_json,mensaje);
    if(not error){
      if(mensaje_json["flash"]==1){
        digitalWrite(pinflash, HIGH);
        Serial.println(DEBUG_STRING + "Encendiendo Flash...");
      }else{
        digitalWrite(pinflash, LOW);
        Serial.println(DEBUG_STRING + "Apagando Flash...");
      }
      mqtt_client.publish(topic_PUB_flash.c_str(), mensaje.c_str());
    }
  }else if (String(topic) == topicCamara) {
    DynamicJsonDocument mensaje_json(200);
    DeserializationError error = deserializeJson(mensaje_json, mensaje);
    if (!error) {
      if(int(mensaje_json["X"])>0){
        Serial.println("Girando a la derecha");
        digitalWrite(left, LOW);
        digitalWrite(rigth, HIGH);
      }else if(int(mensaje_json["X"])<0){
        Serial.println("Girando a la izquierda");
        digitalWrite(left, HIGH);
        digitalWrite(rigth, LOW);
      }else if (int(mensaje_json["Y"])>0){
        Serial.println("Cambiando flash");
        digitalWrite(pinflash, !digitalRead(pinflash));
        String msg;
        if(digitalRead(pinflash)){
          msg = "{\"flash\":1}";
        }else{
          msg = "{\"flash\":0}";
        }
        mqtt_client.publish(topic_PUB_flash.c_str(), msg.c_str());
      }else if (int(mensaje_json["Y"])<0){
        Serial.println("Centrando cámara");
        digitalWrite(left, HIGH);
        digitalWrite(rigth, HIGH);
      }else if (int(mensaje_json["X"])==0){
        Serial.println("Parando motor");
        digitalWrite(left, LOW);
        digitalWrite(rigth, LOW);
      }
    }
  }
}
```
Subfunción para la configuración de la instancia de la cámara. Dicha clase se define en la librería "esp_camera.h", incluida en este programa. Lo más relevante en esta subfunción es la calidad de /fotos/imagen configurada, y el número de buffers de lectura del sensor:
```arduino
void config_init() {
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.frame_size = FRAMESIZE_HD;
  config.pixel_format = PIXFORMAT_JPEG; 
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 12;
  config.fb_count = 2;
}
```
Setup del programa. Se realizan todas las incializaciones necesarias:
```arduino
void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();
  pinMode(left,OUTPUT);
  pinMode(rigth,OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(pinflash, OUTPUT);
  config_init();
  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }
  sensor_t * s = esp_camera_sensor_get();
  s->set_vflip(s, 0);        //1-Upside down, 0-No operation
  s->set_hmirror(s, 0);      //1-Reverse left and right, 0-No operation
  s->set_brightness(s, 1);   //up the blightness just a bit
  s->set_saturation(s, -1);  //lower the saturation

  conecta_wifi();
  startCameraServer();
  mqtt_client.setServer(mqtt_server.c_str(), 1883);
  mqtt_client.setBufferSize(512); // para poder enviar mensajes de hasta X bytes
  mqtt_client.setCallback(procesa_mensaje);
  conecta_mqtt();

  String flash_inicial = "{\"flash\": 0}";
  if (!mqtt_client.connected()) {
    conecta_mqtt();
  }else{
    mqtt_client.publish(topic_PUB_flash.c_str(),flash_inicial.c_str());
  }
}
```
Bucle principal del programa. Se comprueba constantemente la conexión de la cámara tanto a Wifi como a MQTT, y se manda un comando de foto en un intervalo de tiempo configurado por defecto a 60 minutos, aunque es configurable por el usuario mediante MQTT en  la función callback"procesa_mensaje" descrita anteriormente:
```arduino
void loop() {
  static unsigned long ultimo_mensaje=0;
  static unsigned long ahora=0;
  ahora = millis();

  if(WiFi.status() != WL_CONNECTED) {
    Serial.println(DEBUG_STRING + "Reconectando a Wifi...");
    conecta_wifi();
    digitalWrite(ledRojo,HIGH);
    digitalWrite(ledVerde,LOW);
  }else{
    digitalWrite(ledRojo,LOW);
    digitalWrite(ledVerde,HIGH);
  }

  if (!mqtt_client.connected()) {
    Serial.println(DEBUG_STRING + "Reconectando a MQTT...");
    conecta_mqtt();
  }

  mqtt_client.loop(); // esta llamada para que la librería recupere el control

  if (ahora - ultimo_mensaje >= tiempo_foto*60000) { // Mandamos foto automáticamente cada "tiempo_foto" minutos
    ultimo_mensaje = ahora;
    mqtt_client.publish(topic_PUB_foto.c_str(), mensajefoto.c_str());
  }
}
```
El código completo puede verse [AQUÍ](/CodigosArduino/CameraServer_GR31/CameraServer_GR31.ino)

A continuación, se adjunta el código del Arduino Nano.

Primero, se incluyen todas las librerias, variables y pines necesarios:
```arduino
#include <Stepper.h>

// Pines de control del motor paso a paso
const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;
const int buttonPin = 6;
const int left = 7;
const int rigth = 8;

int posicionActual = 0;
const int angle = 10;
bool origin = false; // inicializamos al modo de funcionamiento normal
const int stepsPerRevolution = 2048;  // Cambiar según la especificación del motor
const int vel = 8;

Stepper myStepper(stepsPerRevolution,IN1,IN3,IN2,IN4);
```
Subfunciones auxiliares para la conversión de pasos a grados y viceversa:
```arduino
//-----------------------------------------------------
int degree2steps(const int degrees) {
  int steps = int(degrees * stepsPerRevolution / 360);
  return steps;
}
//-----------------------------------------------------
int steps2degree(const int steps) {
  int degree = int(steps * 360 / stepsPerRevolution);
  return degree;
}
```
Subfunción para realizar la calibración de la cámara. Se hace girar el motor en sentido antihorario hasta que se detecte una pulsación del final de carrera, momento en el que se considera que la cámara está en la posición 0.
```arduino
void recuperarOrigen() {
  // Nos movemos al origen
  while (!origin) {
    if(digitalRead(buttonPin)) {
      Serial.println("Pulsación detectada");
      origin = true;
    } else {
      myStepper.step(-1);
    }
  }
  // Fijamos de nuevo el origen compensando el desfase para poder hacer movimientos relativos
  posicionActual = 0;
  Serial.println("Calibracion completada");
}
```
Subfunción para el control del motor. En función del comando recibido a través de los pines configurados, se realiza un movimiento en un sentido u otro:
```arduino
void controlMotor(const int comando) {
  if ((comando > 0) && (posicionActual < 360 )) { // Comprobamos que estamos dentro del rango
    Serial.println("Moving " + String(angle) + " degrees");
    myStepper.step(degree2steps(angle));
    posicionActual = posicionActual + angle;
    Serial.println("Movement completed");
  } else if ((comando < 0) && (posicionActual > 0)) {  // Comprobamos que estamos dentro del rango
    Serial.println("Moving " + String(angle) + " degrees");
    myStepper.step(degree2steps(-angle));
    posicionActual = posicionActual - angle;
    Serial.println("Movement completed");
  }
}
```
Setup del programa. Se hacen todas las inicializaciones necesarias, y se llama a la función "calibrarOrigen" para llevar a la cámara a su posición inicial: 
```arduino
void setup() {
  // Inicializar la comunicación serial
  Serial.begin(115200);
  pinMode(buttonPin, INPUT); // Configuramos el pin del botón
  pinMode(left,INPUT);
  pinMode(rigth,INPUT);
  // Configura el objeto AccelStepper
  myStepper.setSpeed(vel);  
  recuperarOrigen();
  origin = false;
}
```
Bucle principal del programa. Se comprueba constantemente el estado de los pines de comando para realizar su acción correspondiente en consecuencia:
```arduino
void loop() {
  if((digitalRead(left))&&(digitalRead(rigth))){
    Serial.println("Centrando cámara");
    recuperarOrigen();
  }else if((digitalRead(left))&&(!digitalRead(rigth))){
    Serial.println("Girando a la izquierda");
    controlMotor(-1);
    origin = false;
  }else if((!digitalRead(left))&&(digitalRead(rigth))){
    Serial.println("Girando a la derecha");
    controlMotor(1);
    origin = false;
  }
}
```
El código completo puede verse [AQUÍ](/CodigosArduino/ControlMotor_GR31/ControlMotor_GR31.ino).
#### Diseño 3D de la carcasa de la cámara y su sistema de movimiento

Para alojar la cámara y todos los elementos que componen su sistema de movimiento, se ha usado la herramienta Fusion 360 de Autodesk. El diseño está compuesto de cuatro partes principales.

##### Carcasa de la ESP32 Wrover Cam

Para el diseño de dicha carcasa, se ha partido de un diseño de internet para una ESP32 común, y se le han realizado todas las modificaciones necesarias para poder alojar nuestra ESP32 Wrover Cam. La carcasa se ha diseñado con un sistema de capas para la conexión de los cables y su traspaso a la caja por el eje que une la cámara al motor. Además, en la parte frontal se ha implantado un diseño de rejilla para proporcionarle ventilación al chip de la placa. Dicho diseño queda reflejado en la siguiente /fotos/imagen.

<p align="center">
  <img src="/fotos/image-16.png" alt="Descripción de la /fotos/imagen">
</p>

##### Eje de movimiento

Para unir la carcasa de la cámara con el eje del motor, se ha diseñado un eje que además de realizar la función de unión entre ambos componentes, proporcione tanto un hueco para el cable de la cámara como para el resto de cables de los pines, uniéndose la desembocadura de ambos zócalos al final del eje. Además, se han añadido elementos para la unión de las piezas despúes de su impresión, y un mástil que será el encargado de accionar el final de carrera en la calibración de la posición de la cámara. También se ha añadido un anillo al rededor del eje que evite el movimiento de la cámara en el eje Z. Dicho diseño queda reflejado en la siguiente /fotos/imagen.

<p align="center">
  <img src="/fotos/image-17.png" alt="Descripción de la /fotos/imagen">
</p>

##### Zócalo para los componentes del sistema de movimiento

La siguiente pieza es el zócalo donde se alojan todos los componentes del sistema de movimiento, como son el propio motor paso a paso, su driver, el Arduino Nano y el final de carrera. Se une a la caja del sistema de movimiento mediante unos taladros donde posteriormente irán alojados unos tornillos. Se han suavizado toods los bordes de la pieza para evitar que un cable accidentalmente pueda dañarse con algún borde filoso. Dicho diseño queda reflejado en la siguiente /fotos/imagen.

<p align="center">
  <img src="/fotos/image-18.png" alt="Descripción de la /fotos/imagen">
</p>

##### Caja del sistema de movimiento

La siguiente pieza es la caja donde se aloja todo el sistema de movimiento de la cámara. De nuevo, en la tapa se ha instaurado una rejilla para permitir la ventilación de todos los componentes. Disponde de agujeros para la colocación de los leds de indicación de conexión y el flash, y para la salida de los cables de alimentación. Dicho diseño queda reflejado en la siguiente /fotos/imagen.

<p align="center">
  <img src="/fotos/image-19.png" alt="Descripción de la /fotos/imagen">
</p>

##### Diseño conjunto

Todo el diseño en conjunto viene reflejado en la siguiente /fotos/imagen.

<p align="center">
  <img src="/fotos/image-20.png" alt="Descripción de la /fotos/imagen">
</p>

Se puede acceder al archivo pinchando [AQUÍ](Impresion3D/CamaraPiero.f3d).
Después de la impresión y el montaje, obtenemos el resultado reflejado en la siguiente /fotos/imagen.

<p align="center">
  <img src="/fotos/image-21.png" alt="Descripción de la /fotos/imagen">
</p>

### Implementación de la pasarela Wifi para el Arduino Mega 2560

Finalmente, no hemos sido capaces de terminar de implementar esto, ya que podemos recibir los comandos de movimiento por MQTT pero no hemos podido hacer que el programa de Simulink de la Arduino Mega reciba dichos datos desde la pasarela. Nos ha dado problemas la comunicacíon serie entre ambos dispositivos. Hemos usado un logic level shifter para realizar dicha comunicación y asegurar que no hubiese problemas con la diferencia de niveles de tensión de procesamiento de ambos dispositivos, pero aún así finalmente no hemos conseguido establecer dicha comunicación, ya que constantemente aparecían valores aleatorios o sin sentido en el buffer de datos de llegada, por lo que no hemos podido establecer el control manual para el Piero, aunque se deja abierta la opción de implementarla en un futuro.

### Diseño del flujo de Nodered

En NodeRed, tenemos un conjunto de bloques para el manejo de la cámara de seguridad y sus funciones, los cuales se detallarán a continuación.

El primer bloque es el dedicado a la lógica para hacer fotos de forma manual, comando que se puede realizar a través de las tres plataformas ofrecidas al usuario, como son NodeRed, Telegram y el mando wifi. Además, se ofrece al usuario la posibilidad de escoger entre hacer la foto con o sin flash. La foto se realiza mediante una petición http al API “/capture” del servidor local de la cámara, gracias al nodo http request. Dicha foto es devuelta en formato buffer de datos, e introducida en el campo content del mensaje de respuesta al nodo Telegram sender. Además, dicha foto es convertida a formato cadena para su almacenamiento en la base de datos denominada “fotos_manual”. Para añadir robustez al programa, se ha añadido una comprobación para verificar si el intento de hacer la foto se ha llevado a cabo satisfactoriamente o no, valorando si el payload que devuelve el http request devuelve error o no, de cara a no almacenar ni enviar fotos corruptas.

<p align="center">
  <img src="/fotos/image-22.png" alt="Descripción de la /fotos/imagen">
</p>

El siguiente bloque es el dedicado a la toma de fotos automáticas, la cual se hace por defecto cada 60 minutos, tal y como se explicó en su correspondiente programa de Arduino. En el dashboard de NodeRed se dispone de un nodo slider para poder configurar el tiempo de guardado de dichas fotos automáticas, el cual puede configurarse desde 1 a 60 minutos. Dichas fotos se guardan en una base de datos denominada “fotos_auto”. 

<p align="center">
  <img src="/fotos/image-23.png" alt="Descripción de la /fotos/imagen">
</p>

El siguiente bloque es el dedicado a la recuperación de las fotos guardas en las dos bases de datos, en función del botón que use el usuario en la petición desde Telegram. De nuevo, se hace una comprobación del estado de la foto antes de mandarla.

<p align="center">
  <img src="/fotos/image-24.png" alt="Descripción de la /fotos/imagen">
</p>

El siguiente bloque es el dedicado a la gestión de las peticiones de control del motor de la cámara y del flash manual, tanto desde la dashboard de NodeRed como desde los botones disponibles en Telegram.

<p align="center">
  <img src="/fotos/image-25.png" alt="Descripción de la /fotos/imagen">
</p>

El siguiente bloque es el dedicado a la gestión de las peticiones de control del Piero, tanto desde la dashboard de NodeRed como desde los botones disponibles en Telegram.

<p align="center">
  <img src="/fotos/image-26.png" alt="Descripción de la /fotos/imagen">
</p>

El siguiente bloque es el encargado de gestionar el video en streaming en la dashboard de NodeRed. Consta de un nodo template en el que hay un código html básico que encierra el contenido de la /fotos/imagen que transmite en directo la cámara, haciendo una petición al servidor que implanta la cámara en el área local. Además, también se gestiona la petición desde Telegram para ver el video en streaming, devolviendo ante dicha petición la URL del servidor donde se encuentra alojado el video en streaming de la cámara.

<p align="center">
  <img src="/fotos/image-27.png" alt="Descripción de la /fotos/imagen">
</p>

Por último, nos encontramos unos nodos auxiliares para hacer un vaciado rápido de las fotos de las bases de datos en caso de que necesitemos hacer una depuración. Estos no se utilizarán normalmente.

<p align="center">
  <img src="/fotos/image-28.png" alt="Descripción de la /fotos/imagen">
</p>

El flujo completo puede verse [AQUÍ](/NodeRed/flows.json).

### Usabilidad del entorno Dashboard de NodeRed y de Telegram 

La dasboard que implementa NodeRed con el flujo anteriormente descrito tiene el siguiente aspecto:

<p align="center">
  <img src="/fotos/image-29.png" alt="Descripción de la /fotos/imagen">
</p>

Como se puede observar, por un lado aparece la /fotos/imagen de la cámara en directo, y además una serie de botones con los que poder interactuar con todos los elementos del sistema, cumpliendo la misma función que el mando diseñado.

Para Telegram, hemos creado un bot controlado mediante el flujo de NodeRed explicado anteriormente. Al iniciarlo, nos ofrece un menú con el que podemos interactuar y de nuevo, realizar la mismas funciones que cumplía el mando.

Al realizar cualquier acción, se notificará a Telegram la acción realizada. Además, haciendo uso del botón "Ver Streaming" del menú "Control Cámara", se nos devolverá un enlace a la dasboard de NodeRed, donde podemos ver el video en directo y de nuevo, interactuar con los elementos del sistema.

<div style="display: flex; justify-content: space-between;">
    <img src="/fotos/IMG_5391.PNG" style="width: 30%;">
    <img src="/fotos/IMG_5392.PNG" style="width: 30%;">
    <img src="/fotos/IMG_5393.PNG" style="width: 30%;">
</div>


## Resumen de enlaces a todos los videos



 Piero moviéndose en línea recta con poca desviación en 4.1 metros (calibración encoders)
 
   [https://youtu.be/kBWgP7cRCLU](https://youtu.be/kBWgP7cRCLU)
   
 Modelo de señalización de obstáculos en función de los sensores
 
   [https://youtu.be/zqo0bPWz1SM](https://youtu.be/zqo0bPWz1SM)
   
 Calibración de los motores y zona muerta
 
   [https://youtu.be/Tgh0nENfXSM](https://youtu.be/Tgh0nENfXSM)
   
 Piero evitando paredes (en un rincón y cerca de la puerta)
 
   [https://youtu.be/VB6QkytTeBs](https://youtu.be/VB6QkytTeBs)

 Demostración del control en bucle abierto
 
   [https://youtu.be/OU3vdd7K3cA](https://youtu.be/OU3vdd7K3cA)

 Demostración del control en bucle cerrado
 
   [https://youtu.be/-JRCHIIsw-Q](https://youtu.be/-JRCHIIsw-Q)

 Cinemática
 
   [https://youtu.be/YsWtWxGMNfY](https://youtu.be/YsWtWxGMNfY)

 Calibración del control de orientación:
 
   - 10 Vueltas incompletas:  [https://youtu.be/_kR8HMQxs_Y](https://youtu.be/_kR8HMQxs_Y)
   - 10 vueltas completas:    [https://youtu.be/Sdw2mhJyUDc](https://youtu.be/Sdw2mhJyUDc)

 Salirendo de clase usando Matlab Function
 
  [https://youtu.be/nUrU1EKVeNY](https://youtu.be/nUrU1EKVeNY)

 Saliendo de clase sin que haya ningún obstáculo
 
   [https://youtu.be/2jOPRIdVmmE](https://youtu.be/2jOPRIdVmmE)
   
 Saliendo de clase evitando los obstáculos
 
   [https://youtu.be/SUVn5_DVqa4](https://youtu.be/SUVn5_DVqa4)
   
 Demostración del proyecto opcional
 
   - Piero con cámara rotatoria:  [https://youtu.be/6Vd62COOqGI](https://youtu.be/6Vd62COOqGI)
   - Cámara controlada por mando: [https://youtu.be/HZeDFFgzWQ8](https://youtu.be/HZeDFFgzWQ8)
