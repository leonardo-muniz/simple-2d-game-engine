import pygame

# Inicialização
pygame.init()

# Tamanho da janela
WIDTH, HEIGHT = 800, 600
window = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Square Movement")

# Cores
GREEN = (0, 255, 0)
BLACK = (0, 0, 0)

# Quadrado
square_size = 50
x, y = (WIDTH - square_size) // 2, (HEIGHT - square_size) // 2
speed = 200  # pixels por segundo

# Relógio
clock = pygame.time.Clock()

# Loop principal
running = True
while running:
    delta_time = clock.tick(60) / 1000  # delta_time em segundos

    # Eventos
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Input
    keys = pygame.key.get_pressed()
    if keys[pygame.K_w] or keys[pygame.K_UP]:
        y -= speed * delta_time
    if keys[pygame.K_s] or keys[pygame.K_DOWN]:
        y += speed * delta_time
    if keys[pygame.K_a] or keys[pygame.K_LEFT]:
        x -= speed * delta_time
    if keys[pygame.K_d] or keys[pygame.K_RIGHT]:
        x += speed * delta_time

    # Limites da tela
    x = max(0, min(WIDTH - square_size, x))
    y = max(0, min(HEIGHT - square_size, y))

    # Desenhar
    window.fill(BLACK)
    pygame.draw.rect(window, GREEN, (x, y, square_size, square_size))
    pygame.display.flip()

pygame.quit()
