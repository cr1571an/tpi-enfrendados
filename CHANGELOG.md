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
**Rama `feature/navegar-menu-juego-estadisticas`**:
  - Navegar en el menu principal. Permitiendo jugar, ver estadisticas y creditos sin salir del juego. Solo con 0 se sale del juego.
**Rama `feature/menu-estadisticas`**:
  - Se determina si hubo un ganador o un empate en la partida. Se muestra el resultado de la partida al finalizarla.
  - Se implementa el menu estadiscticas, donde se muestra un rancking de 10 posiciones.

