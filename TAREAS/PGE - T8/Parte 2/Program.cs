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