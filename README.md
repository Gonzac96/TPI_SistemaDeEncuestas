# Sistema de Encuestas

Este es el Trabajo Práctico Integrador de la materia Programación I.

Es un proyecto académico, escrito en lenguaje C, que implementa un sistema de encuestas con múltiples opciones de respuestas.
Permite:
1. Registrar repetidas veces las respuestas de distintos usuarios para una encuesta fija de 10 preguntas sobre Tecnología.
2. Calcular estadísticas simples por pregunta (moda y porcentaje) y mostrar los resultados ordenados de la opción más votada a la menos votada.

---

## Integrantes

_[Cerqueiro, Gonzalo Matías]_ | Desarrollador


---

## Instrucciones para compilar y ejecutar

### Clonar el repositorio

Desde Code copiamos el HTTPS y escribimos en nuestro git bash:

```bash
git clone https://github.com/Gonzac96/TPI_SistemaDeEncuestas.git
```

Luego nos movemos a la carpeta con:

```bash
cd TPI_SistemaDeEncuestas
```


> A continuación se indican **dos caminos**: uno para **Windows** (MinGW / Zinjai) y otro para **Linux** (GCC).

### 1. Windows 10 / 11

#### Opción rápida con Zinjai (trae su propio MinGW)

1. Abrir el proyecto (`Archivo › Abrir directorio…`) y compilar:  
   `Proyecto › Compilar`  
2. Ejecutar:  
   `Proyecto › Ejecutar`

#### Opción terminal con MinGW-w64

1. Instalar MinGW-w64 y agregar `…\mingw64\bin` al **PATH**.  
2. Abrir *PowerShell* o *CMD* en la raíz del repo:

```bash
gcc src/main.c src/encuesta.c src/respuesta.c -o sistema_encuestas.exe
.\sistema_encuestas.exe
```

### 2. Linux

#### Instalar GCC (en caso de que no lo tenga)

```bash
sudo apt install build-essential      # Debian/Ubuntu/Pop!_OS
```
o
```bash
sudo dnf groupinstall "Development Tools"  # Fedora
```

Luego, en la carpeta del proyecto

```bash
gcc src/main.c src/encuesta.c src/respuesta.c -o sistema_encuestas
./sistema_encuestas
```
