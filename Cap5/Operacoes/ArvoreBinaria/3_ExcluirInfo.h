#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

/* --------------------------*/
pNohArvore ExcluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    int comparacao = pfc(raiz->info, info);

    if (comparacao > 0)
    {
        raiz->esquerda = ExcluirInfoRecursivo(raiz->esquerda, info, pfc);
    }
    else if (comparacao < 0)
    {
        raiz->direita = ExcluirInfoRecursivo(raiz->direita, info, pfc);
    }
    else
    {
        // Caso 1: O nó a ser excluído não tem filhos
        if (raiz->esquerda == NULL && raiz->direita == NULL)
        {
            free(raiz->info);
            free(raiz);
            return NULL;
        }

        // Caso 2: O nó a ser excluído tem somente um filho
        if (raiz->esquerda == NULL)
        {
            pNohArvore temp = raiz->direita;
            free(raiz->info);
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL)
        {
            pNohArvore temp = raiz->esquerda;
            free(raiz->info);
            free(raiz);
            return temp;
        }
        else
        {
            pNohArvore aux = raiz->direita;
            while (aux->esquerda != NULL)
            {
                aux = aux->esquerda;
            }
            // Troca as informações
            void *temp_info = raiz->info;
            raiz->info = aux->info;
            aux->info = temp_info;

            // Exclui o nó sucessor da subárvore direita
            raiz->direita = ExcluirInfoRecursivo(raiz->direita, info, pfc);
        }
    }

    return raiz;
}

/* ----------------------------------------------------------*/
int ExcluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
    if (arvore == NULL || arvore->raiz == NULL)
    {
        return -1; // Árvore vazia
    }
    else
    {
        arvore->raiz = ExcluirInfoRecursivo(arvore->raiz, info, pfc);
        return 0; // Exclusão bem-sucedida
    }
}

#endif // EXCLUIRINFO_ARVORE_BINARIA_H