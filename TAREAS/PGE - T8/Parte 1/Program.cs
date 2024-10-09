using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Security.Cryptography.X509Certificates;
// https://learn.microsoft.com/es-es/dotnet/csharp/language-reference/statements/using
class Program
{
    static void Main()
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
}

public class FileManager
{
    public string LeerArchivo(string ruta)
    {
        using (StreamReader reader = new StreamReader(ruta))
        {
            return reader.ReadToEnd();
        }
    }

    public void EscribirArchivo(string ruta, string contenido)
    {
        using (StreamWriter writer = new StreamWriter(ruta))
        {
            writer.Write(contenido);
        }
    }
}