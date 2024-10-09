using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Security.Cryptography.X509Certificates;
using System.Linq.Expressions;
// https://learn.microsoft.com/es-es/dotnet/csharp/language-reference/statements/using
class Program
{
    static void Main()
    {
        try 
        { 
        FileManager fileManager = new FileManager();
            Utility utility = new Utility();

        // Ejemplo de escritura en archivo
        string rutaEscritura = "archivo.txt";
        string contenido = "Hola, este es un ejemplo de contenido.";

        fileManager.EscribirArchivo(rutaEscritura, contenido);
        Console.WriteLine("Contenido escrito en el archivo.");

        // Ejemplo de lectura de archivo
        string rutaLectura = "archivo.txt";
        string contenidoLeido = fileManager.LeerArchivo(rutaLectura);
        Console.WriteLine("Contenido leído del archivo:");
        Console.WriteLine(contenidoLeido);


        // Ejemplo de uso de Utility
        int resultadoDivision = utility.DividirNumeros(10, 1);
        Console.WriteLine($"Resultado de la división: {resultadoDivision}");

        string textoProcesado = utility.ProcesarCadena("NoSoyNull");
        Console.WriteLine($"Texto != de NULL: '{textoProcesado}'");

        int numeroConvertido = utility.ConvertirFormato("123");
        Console.WriteLine($"Número procesado: {numeroConvertido}");

        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ocurrió un error: {ex.Message}");
        }
    }
}

public class FileManager
{
public string LeerArchivo(string ruta)
    {
        try 
        { 
            using (StreamReader reader = new StreamReader(ruta))
            {
                return reader.ReadToEnd();
            }
        }
        catch(FileNotFoundException)
        {
            Console.WriteLine("El archivo no existe.");
            return string.Empty;
        }
        catch (UnauthorizedAccessException)
        {  
            Console.WriteLine("No tienes permisos para leer el archivo.");
            return string.Empty;
        }
        catch (IOException)
        {  
            Console.WriteLine("Error al leer el archivo.");
            return string.Empty;
        }
    }

    public void EscribirArchivo(string ruta, string contenido)
    {
        try
        {
            using (StreamWriter writer = new StreamWriter(ruta))
            {
                writer.Write(contenido);
            }
        }
        catch (UnauthorizedAccessException)
        {
            Console.WriteLine("No tienes permisos para escribir en este archivo.");
        }
        catch (IOException ex)
        {
            Console.WriteLine($"Ocurrió un error de E/S al escribir en el archivo: {ex.Message}");
        }
    }

}
public class Utility
{
    // Método para dividir dos números con validaciones
    public int DividirNumeros(int numerador, int denominador)
    {
        if (denominador == 0)
        {
        throw new ArgumentOutOfRangeException(nameof(denominador), "El denominador no puede ser cero.");
        }
        return numerador / denominador;
    }

    // Método para procesar una cadena con validaciones
    public string ProcesarCadena(string texto)
    {
        if (string.IsNullOrEmpty(texto))
        { 
        throw new ArgumentNullException(nameof(texto), "El texto no puede ser nulo o vacío.");
        }
        return texto.Trim();
    }

    // Método para convertir una cadena a un número con manejo de excepciones
    public int ConvertirFormato(string numeroTexto)
    {
        if (string.IsNullOrEmpty(numeroTexto))
        { 
        throw new ArgumentNullException(nameof(numeroTexto), "El número en formato texto no puede ser nulo o vacío.");
        }

        try
        {
            return int.Parse(numeroTexto);
        }
        catch (FormatException)
        {
            Console.WriteLine("Formato de número no válido.");
            throw;
        }
    }
}