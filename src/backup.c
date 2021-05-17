#if 0

void
test1(void)
{
    char *files[2] = { "data/right.txt", "data/left.txt" };
    loadfiles(files[0], files[1]);

    para* p = para_first(strings1, count1);
    para* q = para_first(strings2, count2);

    context_mode (p, q, files[0], files[1]);

}


int main(int argc, const char * argv[]) {
    //init_options_files(--argc, ++argv);
    

    test1();
    return 0;
}


#endif