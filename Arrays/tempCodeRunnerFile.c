int readArray(const char *filename, int arr[], int n)
// {
//     FILE *f = fopen(filename, "r");
//     if (!f)
//     {
//         printf("Can't Open File : %s\n", filename);
//         return 0;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         fscanf(f, "%d ", &arr[i]);
//     }
//     fclose(f);
//     return 1;
// }