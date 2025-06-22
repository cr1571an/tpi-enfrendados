# Changelog

Todas las modificaciones importantes del proyecto se documentan en este archivo.

## [Unreleased]

### Añadido
- **Rama `feature/menu-y-turno`**: creada para desarrollo de funcionalidades base.
  - `Menú`: principal básico implementado.
  - `Turnos`: sistema de turnos básico implementado.
  - `Dados`: posibilidad de tirar los dados y obtener resultados aleatorios.
- **Rama `feature/crear-logica-de-victoria-o-fin-partida`**: se desarrolló la lógica central del juego, incluyendo:
  - Lógica para lanzar dados solo desde el stock inicial del jugador.
  - Implementación para seleccionar dados desde la consola en base a tu posicion.
  - Validación para que solo se muestren dados seleccionables.
  - Cálculo de sumatoria de valores de los dados y contador de dados.  
  - Método para imprimir los dados lanzados por el jugador.
- **Rama `ajuste/codigo-sin-comentarios`**:
  - Mostrar los dados en forma horizontal.
  - Mejorar las interfaz de usuario.
  - Validar que solo sea posible penalizar al jugar cuando el oponenete tiene mas de un dado.
  - Validar que el dado elegido se encuentre en el rango permitido.
  - Se agrega resultados de puntajes al final de una partida.

### Pendiente
- Refactorizar la lógica de juego en `main` para modularizar y mejorar la estructura del código.
- Implementar un sistema de estadísticas del juego.
- Ajustar el comportamiento del `Menú Principal` para que solo cierre el juego cuando el usuario lo indique, y permitir la navegación entre distintas opciones del menú sin salir.
- Limpieza de pantalla compatible con Windows y Linux.

