# PieroDIYProject Grupo 31 - Laboratorio de Robótica 2023-24

- [Introducción](#Introducción)
- [Montaje](#Montaje)
- [Programación del Piero-DIY](#programación-del-piero-DIY)
  - [Calibración de los sensores](#calibración-de-los-sensores)
  - [Señalización usando LEDS](#Senalizacion-usando-LEDS)
  - [Motores](#Motores)
  - [Controlador reactivo](#controlador-reactivo)
  - [Encoders de los motores](#encoders-de-los-motores)
  - [Control en Bucle Abierto](#control-en-bucle-abierto)
  - [Control en Bucle Cerrado](#control-en-bucle-cerrado)
  - [Cinemática del Piero](#cinemática-del-piero)
  - [Control de orientación](#control-de-orientación)
- [Modelos para salir de clase](#modelos-para-salir-de-clase)
  - [Salir de clase con Signal Builder](#salir-de-clase-con-signal-builder)
  - [Salir de clase con Waypoints y Matlab Function](#salir-de-clase-con-waypoints-y-matlab-function)
  - [Salir de clase con Waypoints](#salir-de-clase-con-waypoints)
  - [Salir de clase con Waypoints y evitando obstáculos](#salir-de-clase-con-waypoints-y-evitando-obstaculos)

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

 [ ESQUEMA DE CONEXIONADO ]


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

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780545/cfebd189-7147-4493-818c-2ce952ab4edd)

 
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

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/02b28af8-1ccb-43de-bb8e-fce66550cf24)

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
<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/4f1f3c4a-bff1-4af8-9e05-58c12ab89261" alt="Módulo Senalizacion">

<br>Colocamos para cada bit un bloque BitWise y un Boolean, los cuales nos permiten examinar y utilizar el valor de ese bit.
En el caso de la intermitencia, colocamos un bloque Switch para diferenciar los casos de Intermitencia (tren de pulsos) o Estable (bloque constante).

### Motores
Para el modelado de los motores se han creado dos módulos, uno para cada rueda. El diagrama utilizado es el siguiente:
<h1></h1>
<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/2c0d6d2e-4e8e-4f5f-a0fa-08b1ba6b4bdf" alt="Modulo MotorsG31">

Cada uno de los circuitos cuenta con tres digital output: uno para ir hacia delante, otro que va hacia detrás y un enable que lo habilita.





### Controlador reactivo

El siguiente segmento presenta el desarrollo de un nuevo programa destinado a capacitar al robot Piero para detectar y evitar obstáculos mediante el uso de los sensores ubicados en la parte delantera. El programa actúa sobre los motores responsables del movimiento de las ruedas para modificar la dirección del robot y sortear obstáculos de manera efectiva.
La implementación de este programa se basa en tres modelos trabajados previamente: el Modelado de Motores, el Modelado de Sensores y el Modelado de Señalización. Estos modelos proporcionan la base necesaria para que el Piero pueda reconocer obstáculos a través de sus sensores y tomar decisiones en tiempo real para evitar colisiones.

#### Alertas
El sistema creado implementa los cinco estados definidos anteriormente, donde por la entrada recibiremos el valor medido en metros de los sensores izquierdo y derecho. Lo pasaremos a centímetros y lo evaluamos para sacar la salida deseada.

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica23-luis-robotic/assets/145780818/a4b503e6-efd0-4b83-80ff-f7ff7b994fdb" alt="Leds">



### Encoders de los motores

**** Explicar encoders de los motores + foto del modelo 

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
![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/ef5752fc-e72f-4e75-bed5-873314410e70)


#### Piero
Este subsistema se volverá a utilizar en cada uno de los modelos ya que se encarga de decidir si se simulará el modelo del piero o se enviará el control de PWM a los motores tomarán los valores leidos por los encoders. 
Esto se hace con un "Variador de fuente" que elige entre el piero real o Hardware (si se está monitoreando en tiempo real con el piero conectado al equipo) o bien con el modelo del comportamiento de nuestros motores.

**** [Explicar modelo de los motores] Este modelo de comportamiento se obtiene de...

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/c09b0444-f086-4a47-8509-42cbd664a6d0)


### Control en Bucle Cerrado

Para el control de la velocidad en el bucle cerrado haremos algo parecido pero, por supuesto cerrando el bucle.

El modelo que usaremos para llevar a cabo este comportamiento será el siguiente:

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780547/ae0872d5-3f0d-410d-9d9f-f5233ce47bba)


En este caso, el piero andará en linea recta a $2 m/s$ pero sí reaccionará a las perturbaciones corrigiendo la trayectoria y volverá a la velocidad lineal del robot establecida en la referencia ya que acumula el posible error en cada rueda.

Así, probando los resultados, vemos que si lo ejecutamos y nos oponemos al movimiento de una rueda, el PID hace que se recupere y continúe en la dirección que iba.

<img src="[https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/2c0d6d2e-4e8e-4f5f-a0fa-08b1ba6b4bdf](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica23-darioJau/assets/145780547/089d7717-55d5-4a5f-96c2-af797030ae6f)" alt="image">



En el siguiente vídeo se ilustra este funcionamiento

[![Video demostratvo ControlBC](https://img.youtube.com/vi/-JRCHIIsw-Q/0.jpg)](https://www.youtube.com/watch?v=-JRCHIIsw-Q)

Los subsistemas que se utilizan en este caso son el mismo que anteriormente para el modelo del piero y el controlador en bucle cerrrado:

#### ControladorBC

El controlador en este caso lo haremos con un PID para cada rueda en lugar de las look-up tables.

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica23-darioJau/assets/145780547/5e2ddc12-4408-42b7-8187-fe91d34d2f7f)

Utilizo el PID tunner para establecer un tiempo de establecimiento de $1 segundo$ aproximadamente ya que así será suficientemente rápido y el tiempo de subida puede ser del orden de medio segundo, la sobreoscilación será $0%$. Hago lo mismo en los dos PID.

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica23-darioJau/assets/145780547/2a103ff2-9904-4b69-9606-1041e38a22ad)


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

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica23-darioJau/assets/145780547/62d3cd18-0fbb-458d-ba00-890007d819ee)

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

![image](https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica23-darioJau/assets/145780547/73d47b47-15f5-4033-a24b-75a145a859fd)

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

%![image]()

<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/1b6e65d1-6949-432e-a8db-7e9187f3466e" alt="SignalBuilder">



### Salir de clase con Matlab Function
<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/050cedc0-b910-4944-a2e1-df82eafc195c" alt="waypoints">

El modelo Salir de clase con Matlaf Function hace uso del bloque Matlab function, al que se le ha programado un pequeño algoritmo de Pure Pursuit.
<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/4e4621c6-b4a8-4e7d-8144-92bdf4e2b5fb" alt="MF">

Este bloque tomaraá como entrada la matriz de puntos predefinida y la posición X,Y del robot. Como salida, se encarga de proporcionar valores de velocidad lineal y angular adecuados para seguir la trayectoria.
### Salir de clase con Waypoints
<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/b4c160ad-f425-46e8-9102-0a1d6c8ce836" alt="waypoints">
El modelo de Salir de clase con Waypoints hace uso del bloque Pure Pursuit. Este algoritmo es muy utilizados en sistemas de conducción autónoma, donde se proporciona al robot comandos de velocidad lineal y angular para perseguir una trayectoria predefinida con puntos x e y.
<img src="https://github.com/Escuela-de-Ingenierias-Industriales/LaboratorioRobotica-lr2023grupo31/assets/145780818/5bafc313-3558-472d-afe9-73bbd95c5f0e" alt="XY">
Como podemos observar en la simulación, el modelo es preciso.

### Salir de clase con Waypoints y evitando obstáculos



## Resumen de enlaces a todos los videos

**** Editar estos enlaces, grabar los videos que falten y escribir los que ya están repartidos por el MD

 Piero moviéndose en línea recta con poca desviación en 3 metros
 
   https://drive.google.com/file/d/1Fcg5lSjv6q5oTs9PIr2WQYbxixgjgluB/view?usp=sharing
   
 Piero cambiando de color en función de los sensores
 
   https://drive.google.com/file/d/14OFnmPmH7kN_HsWogFRFNirAM9pgJrJD/view?usp=sharing
   
 Calibración de sensores, con varias medidas y su valor
 
   https://drive.google.com/file/d/1OfUWI7DMAnQXR0VtjLFuoKIydAzxXi-r/view?usp=sharing
   
 Piero evitando paredes (en un rincón y cerca de la puerta)
 
   https://drive.google.com/file/d/1iNn1hf_GFbhXEMNcsurv0YRRfCokeF8o/view?usp=sharing


