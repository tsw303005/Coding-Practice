#include <stdio.h>

int main() {
  int p_hp, p_atk, p_def;
  int e_hp, e_atk, e_def;

  scanf("%d %d %d", &p_hp, &p_atk, &p_def);
  scanf("%d %d %d", &e_hp, &e_atk, &e_def);

  int p_dealt_to_e = p_atk - e_def;
  int e_dealt_to_p = e_atk - p_def;

  printf("Battle Start \\^_^/\n");
  while (p_hp > 0 && e_hp > 0) {
    printf("The player dealt %d damage to the enemy and the enemy dealt %d damage to the player\n", p_dealt_to_e, e_dealt_to_p);
    p_hp -= e_dealt_to_p;
    e_hp -= p_dealt_to_e;
    printf("The player has %d HP left and the enemy has %d HP left\n", p_hp, e_hp);
  }
  printf("Battle End \\^_^/\n");
  return 0;
}