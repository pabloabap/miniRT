# miniRT
My first RayTracer with miniLibX


# REVISAR

- [ ] Acne de imagen cuando luz en misma coordenada que el plano.
- [x] Comprobar que no pase la alerta de que no se puede multiplicar dos puntos en una operación vectorial en cualquier imagen.
- [x] Aplicar ambient color al color de los objetos para sacar un color final.
- [x] Aplicar las inversas de matrices de objetos como atributo del objeto en vez de calcularla en cada rayo.
- [ ] Gestionar resolucion de objetos duplicados. Mismos objetos, misma posicion, mismas dimensiones. Combinacion de colores o solo mostramos uno de ellos?
- [ ] Torcer el plano de fondo como si fuera una cuesta y_skewed_r_back.rt, ahora rota raro.
> PRUEBA NO BUENOS RESULTADOS
>
> A 0.2 200,200,200   
> C 0,1.5,0 0.0,0.0,1.0 60   
> L 0.0,2.0,-4.0 1 255,255,255   
> pl 0,0,0 0,1,0 255,255,0   
> pl 0,3,0 0,-1,0 255,0,0   
> pl 0,0,10 0,0.9701425001453319,0.24253562503633297 0,255,0   
> pl -3,0,0 1,0,0 0,0,255   
> pl 3,0,0 -1,0,0 200,200,200

> PRUEBA NO BUENOS RESULTADOS 2
>
> A 0.2 200,200,200   
> C 0,1.5,0 0.0,0.0,1.0 60   
> L 0.0,1.0,0.0 1 255,255,255   
> pl 0,0,0 0,1,0 255,255,0   
> pl 0,3,0 0,-1,0 255,0,0   
> pl 0,0,10 0.577350269189626,0.577350269189626,0.577350269189626 0,255,0
> pl -3,0,0 1,0,0 0,0,255   
> pl 3,0,0 -1,0,0 200,200,200   