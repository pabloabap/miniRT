# Introducción
Para simular la refrexión de la luz sobre una superficie debe existir una 
fuente de luz e implementar un algorithmo de sombreado.

Para sombrear cualquier punto unicamente es necesario conocer 4 vectores:
- **Vector ojo (E)**: Del punto `P` al origen del rayo. Se obtiene con la
negación del vector que va del origen del rayo al punto `P`, lo he 
invertirá la dirección del vector.
- **Vector luz (L)** : Del punto `P` a la fuente de luz. Se obtiene restando
al punto de la fuente de luz, el punto `P`.
- **Vector normal de la superficie(N)**: Vector perpendicular a la superficie
en `P`.
- **Vector de reflexión (R)**: Apuntando a la dirección de rebote de la luz, 
la dirección de reflexión

![alt text](image.png)

## Calculo de la normal de una esfera
