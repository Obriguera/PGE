// FileManager.cs
using System;
using System.IO;

namespace ConsoleApp1
{
    public class FileManager
    {
        private Logger _logger;

        public FileManager(Logger logger)
        {
            _logger = logger;
        }

        public string LeerArchivo(string ruta)
        {
            try
            {
                using (StreamReader reader = new StreamReader(ruta))
                {
                    _logger.Log($"Leyendo archivo: {ruta}");
                    return reader.ReadToEnd();
                }
            }
            catch (FileNotFoundException)
            {
                _logger.Log("El archivo no existe.");
                Console.WriteLine("El archivo no existe.");
                return string.Empty;
            }
            catch (UnauthorizedAccessException)
            {
                _logger.Log("No tienes permisos para leer el archivo.");
                Console.WriteLine("No tienes permisos para leer el archivo.");
                return string.Empty;
            }
            catch (IOException ex)
            {
                _logger.Log($"Error al leer el archivo: {ex.Message}");
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
                    _logger.Log($"Escribiendo archivo: {ruta}");
                    writer.Write(contenido);
                }
            }
            catch (UnauthorizedAccessException)
            {
                _logger.Log("No tienes permisos para escribir en este archivo.");
                Console.WriteLine("No tienes permisos para escribir en este archivo.");
            }
            catch (IOException ex)
            {
                _logger.Log($"Ocurrió un error de E/S al escribir en el archivo: {ex.Message}");
                Console.WriteLine($"Ocurrió un error de E/S al escribir en el archivo: {ex.Message}");
            }
        }
    }
}
