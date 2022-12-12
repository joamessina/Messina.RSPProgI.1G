//Dada la estructura eMascota crear una función constructora base y una parametrizada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct
{
    int id;
    char marca[20];
    char tipo[20];
    int edad;
    float altura;
} eMascota;
eMascota* mascota_newParametros(char *idStr, char *marcaStr, char *tipoStr,char *edadStr,char *alturaStr);
eMascota* mascota_new();
int destruirMascota(eMascota *mascotaInd);
int mascota_setAltura(eMascota *this, float peso);
int mascota_getAltura(eMascota *this, float *peso);
int mascota_setId(eMascota *this, int id);
int mascota_getId(eMascota *this, int *id);
int mascota_setMarca(eMascota *this,char *marca);
int mascota_getMarca(eMascota *this,char *marca);
int mascota_setTipo(eMascota *this,char *tipo);
int mascota_getTipo(eMascota *this,char *tipo);
int mascota_setEdad(eMascota *this, int edad);
int mascota_getEdad(eMascota *this, int *edad);
int escribirBinario(eMascota *mascota);
int escribirArchivoTexto(eMascota*mascota);


int main()
{
    eMascota *mascota1= NULL;
    eMascota *mascota2=NULL;
    mascota1=mascota_newParametros("1","callejero","Gato","5","1.50");
    mascota2=mascota_newParametros("2","siames","Gato","2","1.30");
    escribirArchivoTexto(mascota1);
    escribirBinario(mascota2);
    return 0;
}

int mascota_setId(eMascota *this, int id)
{
    int validado = 0;
    if (this != NULL && id > -1)
    {
        this->id = id;
        validado = 1;
    }
    return validado;
}

int mascota_getId(eMascota *this, int *id)
{
    int validado = 0;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        validado = 1;
    }
    return validado;
}
;
int mascota_setMarca(eMascota *this,char *marca)
{
    int validado = 0;
    if (this != NULL && strlen(marca) <= 20 )
    {
        strcpy(this->marca, marca);
        validado = 1;
    }
    return validado;
}
int mascota_getMarca(eMascota *this,char *marca)
{
    int validado = 0;
    if (this != NULL)
    {
        strcpy( marca,this->marca);
        validado = 1;
    }
    return validado;
}
int mascota_setTipo(eMascota *this,char *tipo)
{
    int validado = 0;
    if (this != NULL && strlen(tipo) <= 20 )
    {
        strcpy( this->tipo, tipo);
        validado = 1;
    }
    return validado;
}
int mascota_getTipo(eMascota *this,char *tipo)
{
    int validado = 0;
    if (this != NULL )
    {
        strcpy(tipo,this->tipo);
        validado = 1;
    }
    return validado;
}

int mascota_setAltura(eMascota *this, float altura)
{
    int validado = 0;
    if (this != NULL && altura>0)
    {
        this->altura = altura;
        validado = 1;
    }
    return validado;
}
int mascota_getAltura(eMascota *this, float *altura)
{
    int validado = 0;
    if (this != NULL )
    {
        *altura = this->altura;
        validado = 1;
    }
    return validado;
}
;
int destruirMascota(eMascota *mascotaInd)
{
    int validado = 0;
    if (mascotaInd != NULL)
    {
        free(mascotaInd);
        validado = 1;
    }
    return validado;
};
int mascota_setEdad(eMascota *this, int edad)
{
    int validado = 0;
    if (this != NULL && edad > -1)
    {
        this->edad = edad;
        validado = 1;
    }
    return validado;
}

int mascota_getEdad(eMascota *this, int *edad)
{
    int validado = 0;
    if (this != NULL && edad != NULL)
    {
        *edad = this->edad;
        validado = 1;
    }
    return validado;
}
eMascota* mascota_new()
{
    eMascota *auxMascota = NULL;
    auxMascota = (eMascota*) malloc(sizeof(eMascota));
    auxMascota->id=0;
    auxMascota->altura=0;
    auxMascota->edad=0;
    strcpy( auxMascota->marca," ");
    strcpy( auxMascota->tipo," ");
    return auxMascota;
}

eMascota* mascota_newParametros(char *idStr, char *marcaStr, char *tipoStr,char *edadStr,char *alturaStr)
{
    eMascota *auxMascota;
    auxMascota = mascota_new();
    if (auxMascota != NULL && idStr != NULL && marcaStr != NULL
            && tipoStr != NULL && alturaStr != NULL  && edadStr!= NULL)
    {

        if (!
                (
                    mascota_setAltura(auxMascota,atof(alturaStr))
                    && mascota_setId(auxMascota, atoi(idStr))
                    && mascota_setMarca(auxMascota,marcaStr)
                    && mascota_setEdad(auxMascota,atoi(edadStr))
                    && mascota_setTipo(auxMascota,tipoStr))

           )
        {
            puts("Hubo un problema al crear el vehiculo");
            free(auxMascota);
            auxMascota = NULL;
            system("pause");
        }

    }

    return auxMascota;
}
int escribirArchivoTexto(eMascota*mascota)
{
    /*ESCRITURA EN ARCHIVO DE TEXTO*/
    FILE *f;
    char path[30];
    char confirma;
    int validado=0;
    printf("Ingrese nombre a guardar archivo\n");

    fflush(stdin);
    gets(path);
    strcat(path,".txt");
    f =fopen(path,"r");


    if(f != NULL )
    {

        printf("El archivo ya existe se va a sobreescribir, desea continuar?\n");
        fflush(stdin);
        scanf("%c", &confirma);
        confirma=        tolower(confirma);
        if(confirma != 's')
        {
            printf("Operacion cancelada por el usuario\n");
        }

    }

    if(confirma == 's' || f== NULL)
    {

        char tipo[20];
        float altura;
        int edad;
        char marca[20];
        int id;
        f =fopen(path,"w");
        mascota_getTipo(mascota,tipo);
        mascota_getId(mascota,&id);
        mascota_getAltura(mascota,&altura);
        mascota_getMarca(mascota,marca);
        mascota_getEdad(mascota,&edad);
        fprintf(f,"%s,%s,%s,%s %s\n","Id","Marca","Tipo","Altura","Edad");
        fprintf(f,"%d,%s,%s,%.2f %d\n",id,marca,tipo,altura,edad);
        printf("Archivo de texto guardado exitosamente\n");
        validado=1;
    }

    fclose(f);
    return validado;
}
int escribirBinario(eMascota *mascota)
{
    /*ESCRITURA EN ARCHIVO BINARIO*/
    FILE *f;
    char binaryPath[30];
    char confirma;
    int validado=0;
    printf("Ingrese nombre a guardar archivo binario\n");
    fflush(stdin);
    gets(binaryPath);
    strcat(binaryPath,".bin");
    f =fopen(binaryPath,"rb");
    if(f != NULL )
    {
        confirma='n';
        printf("El archivo ya existe se va a sobreescribir, desea continuar?\n");
        fflush(stdin);
        scanf("%c", &confirma);
        confirma= tolower(confirma);
        if(confirma != 's')
        {
            printf("Operacion cancelada por el usuario\n");
        }

    }
    if(confirma == 's' || f== NULL)
    {
        f =fopen(binaryPath,"wb");
        fwrite(mascota,sizeof(eMascota),1,f);
        printf("Archivo binario guardado exitosamente\n");
        validado=1;
    }


    fclose(f);
    return validado;
}
