typedef struct para {
	char **base;
	int filesize;
	int start;
	int stop;
	char *first_line;
	char *second_line;
} para;

para 
*para_make(char **base, int filesize, int start, int stop)
{
	para *p = malloc(sizeof(para));
	if (p == NULL) {
		return NULL;
	}
	p->base = base;
	p->filesize = filesize;
	p->start = start;
	p->stop  = stop;
	p->first_line  = (p == NULL || start < 0) ? NULL :
		p->base[start];
	p->second_line = (p == NULL || start < 0 || filesize < 2) ?
		NULL : p->base[start + 1];

	return p;
}

para
*para_first(char **base, int size)
{
	para *p = para_make(base, size, 0, -1);
	return para_next(p);
}

void
para_destroy(para *p)
{
	if (p->base != NULL) {
		free(p->base);
	}
	if (p != NULL) {
		free(p);
	}

}

para
*para_next(para *p)
{
	int i;

	if (p == NULL || p->stop == p->first_line) {
		return NULL;
	}
	para *pnew = para_make(p->base, p->filesize, p->start + 1, 
		p->start + 1);
	for (i = pnew->start; i < p->filesize
		&& strcmp(p->base[i], "\n") != 0; i++)
	{

	}
	p->stop = i;

	if (pnew->start >= p->filesize) {
		para_destroy(p);
		pnew = NULL;
	}
	return pnew;
}

int
para_equal(para *p, para *q)
{
	int i;
	int j;
	int equal;

	if (p == NULL || q == NULL) {
		return 0;
	}
	if (p->filesize != q->filesize) {
		return 0;
	}
	if (p->start >= p->filesize || q->start >= q->filesize) {
		return 0;
	}
	
	i = p->start;
	j = q->start;
	equal = 0;
	while ((equal = strcmp(p->base[i], q->base[j])) == 0
		&& i < p->stop && j < q->stop) {
		i++;
		j++;
	}
	return 1;
}

void
para_print(para *p, void (*fp)(const char *))
{
	if (p == NULL) {
		return ;
	}
	for (int i = p->start; 
			i <= p->stop && i  != p->filesize; i++) {
		fp(p->base[i])
	}
}