
intTreeNodePtr buildTree (FILE *in) {
                char word[101];
        fscanf(in, "%s", word);
        //printf("word is %s\n", word);
        if(strcmp(word, "@") == 0||strcmp(word, "") == 0) return NULL;
        else {
                intTreeNodePtr root = (intTreeNodePtr) malloc(sizeof(intTreeNode));
                root->value=atoi(word);
                root -> left = buildTree(in);
                root->right = buildTree(in);
                return root;
        }

}

intTreeNodePtr buildTreeFromString(char *s) {
    FILE *in, *out;
        intTreeNodePtr root;

        in = fopen("tree.in", "w+");
        fputs( s, in);
        fclose(in);
        //in = fmemopen("20 10 30 60 @ @ @ 70 @ 80 @ @ @", 101, "r");
        out = fopen("tree.in","r");
        root = buildTree(out);
        fclose(in);

    
    return root;

}


