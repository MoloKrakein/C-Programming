#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/*
Renardo : AVL Tree, Laporan
Joshua : Score, Laporan
Athaillah : Gameplay loop & Menu

*/

///////////////////////////////////////////////// AVL TREE
struct Node
{
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};


int randomNumber(int modifier)
{
  return rand() % modifier;
}


int height(struct Node *N)
{
  if (N == NULL)
    return 0;
  return N->height;
}

// Calculate max of two integers
int max(int a, int b)
{
  return (a > b) ? a : b;
}

// Create a node
struct Node *newNode(int key)
{
  struct Node *node = (struct Node *)
      malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *y)
{
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x)
{
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

int getBalance(struct Node *N)
{
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Insert a node in the tree
struct Node *insert(struct Node *root, int key)
{
  if (root == NULL)
    return newNode(key);

  if (key < root->key)
    root->left = insert(root->left, key);
  else if (key > root->key)
    root->right = insert(root->right, key);
  else
    return root;

  root->height = 1 + max(height(root->left), height(root->right));

  int balance = getBalance(root);

  // Left Left Case
  if (balance > 1 && key < root->left->key)
    return rightRotate(root);

  // Right Right Case
  if (balance < -1 && key > root->right->key)
    return leftRotate(root);

  // Left Right Case
  if (balance > 1 && key > root->left->key)
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  // Right Left Case
  if (balance < -1 && key < root->right->key)
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// clear the tree
void clearTree(struct Node *root)
{
  if (root == NULL)
    return;
  clearTree(root->left);
  clearTree(root->right);
  free(root);
}

// print the tree in order
void printInorder(struct Node *root)
{
  if (root != NULL)
  {
    printInorder(root->left);
    printf("%d ", root->key);
    printInorder(root->right);
  }
}

// print the tree in pre order
void printPreorder(struct Node *root)
{
  if (root != NULL)
  {
    printf("%d ", root->key);
    printPreorder(root->left);
    printPreorder(root->right);
  }
}

// print the tree in post order
void printPostorder(struct Node *root)
{
  if (root != NULL)
  {
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->key);
  }
}


int isBalance(struct Node *root)
{
  if (root == NULL)
    return 1;
  if (abs(getBalance(root)) > 1)
    return 0;
  return isBalance(root->left) && isBalance(root->right);
}


struct Node *inputNode(struct Node *root, int difficulty)
{
  int key,oldKey;

  key = randomNumber(difficulty);
  //print key
  
  printf(" %d", key);
  root = insert(root, key);
  return root;
}

struct Node *buildNodes(struct Node *root, int x, int difficulty)
{
  int i;
  for (i = 0; i < x; i++)
  {
    root = inputNode(root, difficulty);
    // printf("\nsuccess input %d node\n", i + 1);
  }
  // system("cls");
  return root;
}


////////////////////////////////////////////////////////////////////// Gameplay
//check is it root
int isRoot(struct Node *root, int key)
{
  if (root == NULL)
    return 0;
  if (root->key == key)
    return 1;
  return 0;
}

int play(int difficulty, int x)
{

  int soal;
  char jawab;
  struct Node *root = NULL;
  int benar;
  int jawaban;
  printf("Inserting :");
  root = buildNodes(root, x, difficulty);
  printf("\n");

  printf("The tree is now ready to be played!\n");
  printf("\n");
  printf("Inorder traversal of the tree:\n");
  printInorder(root);
  // printf("\n");
  // printf("Preorder traversal of the tree:\n");
  // printPreorder(root);
  // printf("\n");
  // printf("Postorder traversal of the tree:\n");
  // printPostorder(root);
  printf("\n");
  printf("The tree is now ready to be played!\n");
  printf("Guess the root number: ");
inputagain:
  scanf("%d", &jawaban);
  // soal = randomNumber(difficulty);
  //input to tree
  // if jawaban == root then return 1
  // else return 0
  if (isRoot(root, jawaban))
  {
    printf("\n");
    printf("You are correct!\n");
    benar = 1;
    return benar;
  }
  else
  {
    printf("\n");
    printf("You are wrong!\n");
    printf("The root number is %d\n", root->key);
    benar = 0;
    return benar;
  }
  
}



// extract score to file
void extractScore(int score, char name[], int difficulty)
{
  FILE *file; 
  file = fopen("score.txt", "a"); 
  fprintf(file, "%s %d %d\n", name, score, difficulty); 
  fclose(file);
}

void readScore()
{
  struct score 
  {
    char name[20];
    int score;
    int difficulty;
  } scores[100];

  FILE *file;
  file = fopen("score.txt", "r"); 
  char name[100];
  int score, rank, no,dif;
  rank = 1;
  no = 0;
  while (fscanf(file, "%s %d %d", name, &score, &dif) != EOF) 
  {
    strcpy(scores[no].name, name);
    scores[no].score = score;
    scores[no].difficulty = dif;
    no++;
  }
  fclose(file);
  ///////////////////////////// 
  int i, j;
  for (i = 0; i < no; i++)
  {
    for (j = 0; j < no - 1; j++)
    {
      if (scores[j].score < scores[j + 1].score)
      {
        struct score temp;
        temp = scores[j];
        scores[j] = scores[j + 1];
        scores[j + 1] = temp;
      }
    }
  }
  char diff[20]; 
  printf("============================================================\n");
  printf("| No | Name | Score | Difficulty |\n");
  printf("============================================================\n");
  for (int i = 0; i < no; i++)
  {
    if (scores[i].difficulty == 5)
      strcpy(diff, "Easy");
    else if (scores[i].difficulty == 8)
      strcpy(diff, "Medium");
    else if (scores[i].difficulty == 11)
      strcpy(diff, "Hard");
    
    printf("| %d | %s | %d | %s |\n", rank, scores[i].name, scores[i].score, diff);
    rank++;
  }
  if (no == 0)
  {
    printf("| %d | %s | %d |\n", rank, "Empty", 0, "Empty");
  }
  printf("============================================================\n");
}

// create file
void createFile()
{
  FILE *file;
  file = fopen("score.txt", "w");
  fclose(file);
}

int health(int x){
  if (x == 3)
  {
    return x*5;
  }
  else if (x == 6)
  {
    return x*2;
  }
  else if (x == 9)
  {
    return x/3;
  }
}

// main
int main()
{
  system("cls");
  srand(time(NULL));
  int difficulty;
  char continueGame, rede;
  int choice;
  int key, x, try;
  int check;
  int score, totalScore, lvlmultiply, lvl;
  int menu;
  char userName[100];
    int mod;
  struct Node *root = NULL;
  printf("Welcome to the AVL Tree Game!\n");
diff:
  printf("Please select a difficulty level:\n");
  printf("1. Easy\n");
  printf("2. Medium\n");
  printf("3. Hard\n");
  scanf("%d", &difficulty);
  if (difficulty == 1)
  {
    difficulty = 15;
    x = difficulty / 5;
    try = health(x);
    system("cls");
    printf("You have selected Easy!\n");
    printf("It will take you %d tries to guess the number!\n", try);
    printf("Total generated nodes will be %d!\n", x);
    printf("Your score will be multiplied by %d!\n", x);
    printf("\n");
    printf("Are you ready to play? (y/n) ");
    scanf(" %c", &rede);
    if (rede != 'y')
    {
      goto diff;
    }
  }
  else if (difficulty == 2)
  {
    difficulty = 30;
    x = difficulty / 5;
    try = health(x);
    system("cls");
    printf("You have selected Medium!\n");
    printf("It will take you %d tries to guess the number!\n", try);
    printf("Total generated nodes will be %d!\n", x);
    printf("Your score will be multiplied by %d!\n", x);
    printf("\n");
    printf("Are you ready to play? (y/n) ");
    scanf(" %c", &rede);
    if (rede != 'y')
    {
      goto diff;
    }
  }
  else if (difficulty == 3)
  {
    difficulty = 45;
    x = difficulty / 5;
    try = health(x);
    system("cls");
    printf("You have selected Hard!\n");
    printf("It will take you %d tries to guess the number!\n", try);
    printf("Total generated nodes will be %d!\n", x);
    printf("Your score will be multiplied by %d!\n", x);
    printf("\n");
    printf("Are you ready to play? (y/n) ");
    scanf(" %c", &rede);
    if (rede != 'y')
    {
      goto diff;
    }
  }
  else
  {
    printf("Invalid difficulty level.\n");
    goto diff;
    return 0;
  }
  system("cls");
  printf("%d nodes created!\n", x);
  printf("\n");
  printf("Now playing the game!\n");
  printf("\n");
  menu = 1;
  x = difficulty / 5 + 2;
  lvl = 1;
  lvlmultiply = 1;
  mod = 0;
        mod = x;
  while (menu)
  {
    try = health(x);
    printf("1. Play\n");
    printf("2. Read Score\n");
    printf("3. Exit\n");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
      do
      {
        system("cls");
        mod = mod * lvlmultiply;
        score = play(difficulty, x) * mod;
        if (score > 0)
        {
          totalScore += score;
        }
        else
        {
        try--;
        printf("You have %d tries left!\n", try);
        printf("\n");
        }
        printf("Level %d\n", lvl);
        printf("Score: %d\n", totalScore);
        printf("Do you want to continue? (y/n)");
        clearTree(root);
        scanf(" %c", &continueGame);
        if (continueGame == 'y')
        {
          lvl++;
                 if (lvl == lvl % 5 + 1)
        {
          lvlmultiply++;
          printf("Score Multiplier Updated !\n");
        }
        }
        else if (continueGame == 'n')
        {
          system("cls");
          break;
        }
        else
        {
          printf("\n");
          printf("Invalid input!\n");
          system("pause");
          system("cls");
        }
      } while (try > 0);
      printf("\n");
      printf("Game's Up, Fun's Over!\n");
      printf("\n");
      printf("Your score is %d\n", totalScore);
      printf("\n");
      printf("Please enter your name: ");
      scanf(" %s", userName);
      extractScore(totalScore, userName, x);
      system("cls");
      printf("\n");

      break;
    case 2:
      readScore();
      break;
    case 3:
      printf("Are you want to change difficulty? (y/n) ");
      scanf(" %c", &rede);
      if (rede == 'y')
      {
        system("cls");
        goto diff;
      }
      else if (rede == 'n')
      {
        system("cls");
        printf("Thank you for playing!\n");
        printf("\n");
        printf("Press any key to exit!\n");
        system("pause");
        return 0;
      }
      else
      {
        printf("\n");
        printf("Invalid input!\n");
        system("pause");
        system("cls");
        break;
      }
      return 0;
      break;
    default:
      printf("Invalid input!\n");
      break;
    }
  }

  return 0;
}

