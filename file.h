uint32_t file_make(char *argv, uint32_t buffer)
{
    FILE *f;

    f = fopen(argv, "r");
    if(f == NULL)
    {
        printf("file doesn't open\n");
        return 1; 
    }
    int read = fread(&buffer, 1, sizeof(uint32_t), f);
    fclose(f);
    if(read != 4)
    {
        printf("element conut isn't 4\n");
        return 1;
    }
    else
        return buffer;
}