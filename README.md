## Trabajo práctico 2. TDD.
Completar el trabajo presentado en clase para desarrollar un controlador de led utilizando la
técnica de TDD. Se deben completar las siguientes pruebas

- Después de la inicialización todos los LEDs deben quedar apagados.
- Se puede prender un LED individual.
- Se puede apagar un LED individual.
- Se pueden prender y apagar múltiples LED’s.
- Se pueden prender todos los LEDs de una vez.
- Se pueden apagar todos los LEDs de una vez.
- Se puede consultar el estado de un LED.

Se debe mantener bajo control de versión el código generado.

Entregar:
Repositorio con el archivo con las pruebas unitarias y el código de producción bajo prueba
(preferentemente en bitbucket o github).

## Uso del repositorio

Este repositorio utiliza [pre-commit](https://pre-commit.com) para validaciones de formato. Para trabajar con el mismo usted debería tener instalado:

1. pre-commit (https://pre-commit.com/#install)

Después de clonar el repositorio usted debería ejecutar el siguiente comando:

```
pre-commit install
```

Para generar la documentación del proyecto se utiliza el siguiente comando:

```
make doc

```

Para `compilar` el proyecto se utiliza el siguiente comando:

```
make all
```

## License

This work is distributed under the terms of the [MIT](https://spdx.org/licenses/MIT.html) license.
