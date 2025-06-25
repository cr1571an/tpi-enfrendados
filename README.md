# Enfrendados 🎲

**Enfrendados** es un juego de dados para dos jugadores que combina azar y matemáticas. Fue desarrollado como Trabajo Práctico Integrador para la materia *Programación I*.

## 🎯 Objetivo del juego

El objetivo es sumar la mayor cantidad de puntos en un total de **tres rondas**, o bien **ganar automáticamente** si un jugador se queda sin dados stock.

## 🔄 Inicio del juego

Antes de comenzar las rondas, se realiza una tirada inicial para determinar quién empieza:

1. **Tirada de inicio**:
   - Cada jugador lanza un dado de 6 caras.
   - El jugador con el valor más alto comienza la partida.
   - En caso de empate, ambos lanzan nuevamente hasta desempatar.

2. Luego, comienza la **primera ronda** con el jugador que ganó la tirada inicial.

## 🧩 Mecánica del juego

- Cada jugador comienza con **6 dados de 6 caras** (*dados stock*).
- Entre rondas, se tiran **2 dados de 12 caras** para obtener un **número objetivo**.
- Cada jugador, en su turno:
  1. Lanza los **dados de 12 caras** → se obtiene el número objetivo (suma de ambos dados).
  2. Lanza sus **dados stock**.
  3. Elige una combinación de dados que sumen exactamente el número objetivo.

### ✅ Si logra una tirada exitosa:
- Gana **puntos**: `suma seleccionada * cantidad de dados elegidos`.
- Los **dados elegidos** se transfieren al oponente.
- Si se queda sin dados, **gana automáticamente** y recibe **10,000 puntos** adicionales.

### ❌ Si falla:
- El oponente le transfiere **1 dado**, solo si tiene más de uno.

### 🏁 Fin del juego:
- Cuando se completan **3 rondas**.
- O si un jugador se queda sin dados stock (victoria automática).

### 📊 Estadísticas

La opción **Estadísticas** permite visualizar al jugador con el mayor puntaje obtenido durante las partidas jugadas. Se mostrará su nombre junto al puntaje correspondiente, brindando un resumen del mejor rendimiento registrado.


### 👥 Créditos

La opción **Créditos** muestra la información de los integrantes del equipo desarrollador, incluyendo:

- Apellido y nombre  
- Legajo de cada integrante

También se incluye el **nombre del equipo** que llevó a cabo el desarrollo del juego.


## 🔧 Tecnologías

- Lenguaje: **C++**

## 📁 Estructura del proyecto

## 👨‍💻 Autores

- Cristian Nicolás Sánchez
- Ignacio Daniel Demata
- Juan Pablo Torreiro
- Ulises Sergio Martín Aguirre

## 📚 Cátedra

- **Cátedra:** Programación I  
- **Carrera:** Tecnicatura Universitaria en Programación  
- **Facultad:** UTN - Facultad Regional Gral. Pacheco  
- **Año:** 2025



