#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dentro_ret (int x0, int y0, int x1, int y1, int x, int y)
{
    if ((x>=x0&&x<=x1)&&(y>=y0&&y<=y1))
    {
        return 1;
    }
    return 0;
}

int main()
{
    int x0, y0, x1, y1, x, y;
    printf("Insira x0 e y0 do canto inferior esquerdo de um retangulo: ");
    scanf("%d %d", &x0, &y0);
    printf("Insira x1 e y1 do canto superior direito de um retangulo: ");
    scanf("%d %d", &x1, &y1);
    printf("Insira x e y para verifica se pertencem ao retangulo: ");
    scanf("%d %d", &x, &y);
    printf("\n%d", dentro_ret(x0, y0, x1, y1, x, y));
}