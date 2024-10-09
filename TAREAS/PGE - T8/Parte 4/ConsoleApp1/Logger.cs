// Logger.cs
using System;
using System.IO;

namespace ConsoleApp1
{
    public class Logger
    {
        private string _logFilePath;

        public Logger(string logFilePath)
        {
            _logFilePath = logFilePath;
        }

        public void Log(string message)
        {
            try
            {
                using (StreamWriter writer = new StreamWriter(_logFilePath, true))
                {
                    writer.WriteLine($"{DateTime.Now}: {message}");
                }
            }
            catch (IOException)
            {
                Console.WriteLine("Error al escribir en el archivo de log.");
            }
        }
    }
}
