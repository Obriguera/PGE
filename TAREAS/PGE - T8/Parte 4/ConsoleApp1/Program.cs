// Program.cs
using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main()
        {
            Logger logger = new Logger("log.txt");
            FileManager fileManager = new FileManager(logger);
            Utility utility = new Utility(logger);

            while (true)
            {
                try
                {
                    Console.WriteLine("Seleccione una opción:");
                    Console.WriteLine("1. Leer archivo");
                    Console.WriteLine("2. Escribir archivo");
                    Console.WriteLine("3. Dividir números");
                    Console.WriteLine("4. Procesar cadena");
                    Console.WriteLine("5. Convertir formato");
                    Console.WriteLine("6. Salir");
                    Console.Write("Opción: ");
                    string opcion = Console.ReadLine();

                    switch (opcion)
                    {
                        case "1":
                            Console.Write("Ingrese la ruta del archivo a leer: ");
                            string rutaLectura = Console.ReadLine();
                            string contenidoLeido = fileManager.LeerArchivo(rutaLectura);
                            Console.WriteLine("Contenido leído del archivo:");
                            Console.WriteLine(contenidoLeido);
                            break;

                        case "2":
                            Console.Write("Ingrese la ruta del archivo a escribir: ");
                            string rutaEscritura = Console.ReadLine();
                            Console.Write("Ingrese el contenido a escribir: ");
                            string contenido = Console.ReadLine();
                            fileManager.EscribirArchivo(rutaEscritura, contenido);
                            Console.WriteLine("Contenido escrito en el archivo.");
                            break;

                        case "3":
                            Console.Write("Ingrese el numerador: ");
                            int numerador = int.Parse(Console.ReadLine());
                            Console.Write("Ingrese el denominador: ");
                            int denominador = int.Parse(Console.ReadLine());
                            int resultadoDivision = utility.DividirNumeros(numerador, denominador);
                            Console.WriteLine($"Resultado de la división: {resultadoDivision}");
                            break;

                        case "4":
                            Console.Write("Ingrese una cadena a procesar: ");
                            string texto = Console.ReadLine();
                            string textoProcesado = utility.ProcesarCadena(texto);
                            Console.WriteLine($"Texto procesado: '{textoProcesado}'");
                            break;

                        case "5":
                            Console.Write("Ingrese un número en formato texto: ");
                            string numeroTexto = Console.ReadLine();
                            int numeroConvertido = utility.ConvertirFormato(numeroTexto);
                            Console.WriteLine($"Número convertido: {numeroConvertido}");
                            break;

                        case "6":
                            return;

                        default:
                            Console.WriteLine("Opción no válida.");
                            break;
                    }
                }
                catch (Exception ex)
                {
                    logger.Log($"Ocurrió un error: {ex.Message}");
                    Console.WriteLine($"Ocurrió un error: {ex.Message}");
                }
            }
        }
    }
}
