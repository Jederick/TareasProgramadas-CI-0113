# La estructura de una tienda es la siguiente:

| Variable         | Tamaño en bytes | Offset |
| -----            | --------------- | -------|
|Id                | 15              | 0      |
|Direcion internet | 24              | 15     |
|Direccion Fisica  | 24              | 39     |
|Telefono          | 8               | 63     |
|Inventario        | n*28            | 71     |

n = Cantidad de Productos 

# Instrucciones del programa

Para compilar y crear la biblioteca ejecutar: make

Para compilar y activar las opciones de depuracion de los tests
ejecutar: make test
Para correr los tests ejecutar: bin/tests
