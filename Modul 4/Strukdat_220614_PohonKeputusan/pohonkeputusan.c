#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct bstnode {
	char kolom[6];
	char data;
    struct bstnode *kiri, *kanan;
} BSTNode;

typedef struct bst {
    BSTNode *akar;
    unsigned int ukuran;
} BST;

BSTNode* buat_node(char status, char kolom[]) {
    BSTNode *node_baru = (BSTNode*) malloc(sizeof(BSTNode));
    strcpy(node_baru->kolom, kolom);
    node_baru->data = status;
    node_baru->kiri = node_baru->kanan = NULL;
    return node_baru;
}

BSTNode* tambah_node(BSTNode *akar, char rela, char percaya, char kenal) {
    if (akar == NULL) {
    	return buat_node(rela, "rela");
	}
	
    if (rela == 'Y' && akar->kiri == NULL) {
        akar->kiri = buat_node(rela, "rela");
	}
    else if (rela == 'G' && akar->kanan == NULL) {
    	akar->kanan = buat_node('P', "percaya");
	}
	
    if (percaya == 'Y' && akar->kanan->kiri == NULL) {
        akar->kanan->kiri = buat_node(percaya, "percaya");
	}
    else if (percaya == 'G' && akar->kanan->kanan == NULL) {
    	akar->kanan->kanan = buat_node('K', "kenal");
	}
	
    if (kenal == 'Y' && akar->kanan->kanan->kiri == NULL) {
        akar->kanan->kanan->kiri = buat_node(kenal, "kenal");
	}
    else if (kenal == 'G' && akar->kanan->kanan->kanan == NULL) {
    	akar->kanan->kanan->kanan = buat_node(kenal, "kenal");
	}
	
	return akar;
}

void inisialisasi(BST *bst) {
    bst->akar = NULL;
    bst->ukuran = 0u;
}

bool temukan(BST *bst, char rela, char percaya, char kenal) {
    if (bst->akar == NULL) {
    	return false;
	}
	
	if ( bst->akar != NULL && bst->akar->kiri != NULL && bst->akar->kanan != NULL &&
    	 bst->akar->kanan->kiri != NULL && bst->akar->kanan->kanan != NULL &&
    	 bst->akar->kanan->kanan->kiri != NULL && bst->akar->kanan->kanan->kanan != NULL )
	{
		return true;
	}
    else {
    	return false;
	}
}

void tambah(BST *bst, char rela, char percaya, char kenal) {
    if (!temukan(bst, rela, percaya, kenal)) {
        bst->akar = tambah_node(bst->akar, rela, percaya, kenal);
        bst->ukuran++;
    }
}

char tentukan(BSTNode *akar, char rela, char percaya, char kenal) {
    if (akar->kiri == NULL && akar->kanan == NULL) return akar->data;

    if (akar->data == 'R')
    {
        if (rela == 'Y') return tentukan(akar->kiri, rela, percaya, kenal);
        else if (rela == 'G') return tentukan(akar->kanan, rela, percaya, kenal);
    }
    else if (akar->data == 'P')
    {
        if (percaya == 'Y') return tentukan(akar->kiri, rela, percaya, kenal);
        else if (percaya == 'G') return tentukan(akar->kanan, rela, percaya, kenal);
    }
    else if (akar->data == 'K')
    {
        if (kenal == 'Y') return tentukan(akar->kiri, rela, percaya, kenal);
        else if (kenal == 'G') return tentukan(akar->kanan, rela, percaya, kenal);
    }
}

int main()
{
	BST set;
    inisialisasi(&set);
    tambah(&set, 'R', 'P', 'K');
	char teks[43], rela, percaya, kenal, pinjemin;
	int no = 0;
	FILE *berkas = fopen("data.txt", "a+");
	
	fgets(teks, 43, (FILE*)berkas);
	do {
		fgets(teks, 43, (FILE*)berkas);
//		teks[7] itu nilai rela, teks[17] itu nilai percaya, teks[27] itu nilai kenal
		tambah(&set, teks[7], teks[17], teks[27]);
		no += 1;
		
		if (feof(berkas)) break;
	} while (1);
	
	scanf("%c %c %c", &rela, &percaya, &kenal);
	pinjemin = tentukan(set.akar, rela, percaya, kenal);
	printf("=%c=", pinjemin);
	
	fprintf(berkas, "\n.%d.....%c.........%c.........%c.........%c", no, rela, percaya, kenal, pinjemin);
	fclose(berkas);
}
