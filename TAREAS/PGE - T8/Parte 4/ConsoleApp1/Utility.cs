// Utility.cs
using System;

namespace ConsoleApp1
{
    public class Utility
    {
        private Logger _logger;

        public Utility(Logger logger)
        {
            _logger = logger;
        }

        public int DividirNumeros(int numerador, int denominador)
        {
            if (denominador == 0)
            {
                _logger.Log("El denominador no puede ser cero.");
                throw new ArgumentOutOfRangeException(nameof(denominador), "El denominador no puede ser cero.");
            }
            _logger.Log($"División: {numerador} / {denominador}");
            return numerador / denominador;
        }

        public string ProcesarCadena(string texto)
        {
            if (string.IsNullOrEmpty(texto))
            {
                _logger.Log("El texto no puede ser nulo o vacío.");
                throw new ArgumentNullException(nameof(texto), "El texto no puede ser nulo o vacío.");
            }
            _logger.Log($"Procesando cadena: {texto}");
            return texto.Trim();
        }

        public int ConvertirFormato(string numeroTexto)
        {
            if (string.IsNullOrEmpty(numeroTexto))
            {
                _logger.Log("El número en formato texto no puede ser nulo o vacío.");
                throw new ArgumentNullException(nameof(numeroTexto), "El número en formato texto no puede ser nulo o vacío.");
            }

            try
            {
                int resultado = int.Parse(numeroTexto);
                _logger.Log($"Conversión exitosa: {numeroTexto} a {resultado}");
                return resultado;
            }
            catch (FormatException)
            {
                _logger.Log("Formato de número no válido.");
                Console.WriteLine("Formato de número no válido.");
                throw;
            }
        }
    }
}
