//programa de venta y envios de material didactico,para formular cotizaciones almacenar e imprimir clientes.
#include <stdio.h>//libreria estandar, entrada y salida de datos 
#include <string.h>

struct cliente{
  int id,cp;
  char nombre[20],tel[20],direccion[40], pais[10];

  
};
struct producto{
  int id,precio;
  char nombre[40];
  
};



typedef cliente Cliente;
typedef producto Producto;
 
void portada();
void imprimirCliente(struct cliente);
void imprimirProducto(struct producto);
int selectCliente();
int selectProducto();
int generaCotizacion(struct producto Productos[]);
void imprimirCotizacion(struct cliente, int);

int main(){
//Estructuras
Cliente Clientes[3];
Producto Productos[2];
//Datos estáticos
Clientes[0].id=1;
Clientes[0].cp=48762;
strcpy(Clientes[0].nombre,"Jesus");
strcpy(Clientes[0].tel,"3312289766");
strcpy(Clientes[0].direccion,"Josefa #2 col Sta Carmen");
strcpy(Clientes[0].pais,"México");

Clientes[1].id=2;
Clientes[1].cp=54620;
strcpy(Clientes[1].nombre,"Pedro Neri");
strcpy(Clientes[1].tel,"3374678297");
strcpy(Clientes[1].direccion,"Vicente Suarez #32 col Potrero Nuevo");
strcpy(Clientes[1].pais,"México");

Clientes[2].id=3;
Clientes[2].cp=45680;
strcpy(Clientes[2].nombre,"Arleth Jazmin");
strcpy(Clientes[2].tel,"3321896711");
strcpy(Clientes[2].direccion,"Gomez Farias #21 col Centro");
strcpy(Clientes[2].pais,"México");

Productos[0].id=1;
Productos[0].precio=10;
strcpy(Productos[0].nombre,"Toallitas humedas 10pzas");

Productos[1].id=2;
Productos[1].precio=45;
strcpy(Productos[1].nombre,"Cacahuates Japoneses x 40pzas");


portada();
//Muestra los datos estáticos de la tienda
printf("\n\tClientes registrados:\n");
for(int i=0;i<3;i++){
  imprimirCliente(Clientes[i]);
}
printf("\n\tProductos registrados:\n");
for(int i=0;i<2;i++){
  imprimirProducto(Productos[i]);
}
int id = selectCliente();

//Muestra la cotización
imprimirCotizacion(Clientes[id], generaCotizacion(Productos));


return 0;
}


void portada(){
printf("-------------------------- < > --------------------------\n");
printf("             Cotizaciones Dulce Cruz Viniles \n");
printf("---------------------------------------------------------");
printf("\n\nDescripción:\nEste programa te permite realizar rápidamente una cotizacion, simplemente selecciona el id del cliente, ve seleccionando los artículos, en cada uno ingresa la cantidad, finalmente tendrás una cotización lista.\n\n");
}
void imprimirCliente(struct cliente Cliente){
  printf("id: %i\t nombre: %s\t tel: %s \n",Cliente.id,Cliente.nombre,Cliente.tel);
}
void imprimirProducto(struct producto Producto){
  printf("id: %i\t nombre: %s\t $%i \n",Producto.id,Producto.nombre,Producto.precio);
}
int selectCliente(){
  int id;
  printf("\n\nSelecciona el cliente: ");
  scanf("%i",&id);
  return id;
}

int generaCotizacion(struct producto Productos[]){
  printf("\n-------------------------------\n");
  printf("\tProductos\n");
  int productoID,cantidad,opc, sumatoria=0;
  do{
    printf("\nSeleciona un producto por id\n");
    scanf("%i",&productoID);
    printf("Cantidad: ");
    scanf("%i",&cantidad);
    printf("\n");
    sumatoria=sumatoria+Productos[productoID-1].precio*cantidad;
    printf("Seguir seleccionando?\t [0]Sí  [1]No ----->");
    scanf("%i",&opc);
  }while(opc==0);
return sumatoria;
}
void imprimirCotizacion(struct cliente Cliente,int total){
  printf("###################################\n");
  printf("Cliente: %s\n",Cliente.nombre);
  printf("Teléfono: %s\n",Cliente.tel);
  printf("Pais: %s\n",Cliente.pais);
  printf("Direccion: %s\n",Cliente.direccion);
  printf("Cliente: %i\n",Cliente.cp);
  printf("Total: $%i MXN\n",total);

}
