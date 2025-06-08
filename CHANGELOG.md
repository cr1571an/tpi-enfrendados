# Changelog

Todas las modificaciones importantes del proyecto se documentan en este archivo.

## [Unreleased]

### Añadido
- **Rama `feature/menu-y-turno`: creada para desarrollo de funcionalidades base.
  - `Menú`: principal básico implementado.
  - `Turnos`: sistema de turnos básico implementado.
  - `Dados`: posibilidad de tirar los dados y obtener resultados aleatorios.
- **Rama `feature/crear-logica-de-victoria-o-fin-partida`**: se desarrolló la lógica central del juego, incluyendo:
  - Lógica para lanzar dados solo desde el stock inicial del jugador.
  - Implementación para seleccionar dados desde la consola en base a tu posicion.
  - Validación para que solo se muestren dados seleccionables.
  - Cálculo de sumatoria de valores de los dados y contador de dados.
  - Limpieza de pantalla compatible con Windows y Linux.
  - Método para imprimir los dados lanzados por el jugador.

### Cambiado
- En `feature/crear-logica-de-victoria-o-fin-partida`:
  - Se implementó el flujo de juego completo para un jugador: cálculo de puntajes, penalización y transferencia de dados.
  - Se integró en `main` la lógica de condiciones de victoria o fin de partida.
  - Se agregó corte inmediato del juego en caso de victoria directa.

### Pendiente
- Refactorizar la lógica de juego en `main` para modularizar y mejorar la estructura del código.
- Añadir validaciones adicionales en el flujo de juego.
- Mejorar la interfaz de usuario durante la selección de dados para que sea más intuitiva y clara.
- Implementar un sistema de estadísticas del juego.
- Ajustar el comportamiento del `Menú Principal` para que solo cierre el juego cuando el usuario lo indique, y permitir la navegación entre distintas opciones del menú sin salir.

