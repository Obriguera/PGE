using System;

public class MiEventoArgs : EventArgs
{
   
    public int Numero1 { get; }
    public int Numero2 { get; }
    public char Operador { get; }
    public MiEventoArgs( int numero1, int numero2, char operador)
    {
       
        Numero1 = numero1;
        Numero2 = numero2;
        Operador = operador;
    }
}

public class Publicador
{
    // Declaración del evento con datos personalizados
    public event EventHandler<MiEventoArgs> EventoOcurrido;

    // Método que dispara el evento con un número específico
    public void DispararEvento( int numero1, int numero2,char op)
    {
        // Cuando ocurre el evento, se llama a todos los manejadores registrados
        EventoOcurrido?.Invoke(this, new MiEventoArgs( numero1, numero2,op));
    }
}

public class Suscriptor
{
    float result;
    public void ManejadorEvento(object sender, MiEventoArgs e)
    {
       

        switch (e.Operador)
        {
            case '+':
                result = e.Numero1 + e.Numero2;
                break;
            case '-':
                result = e.Numero1 - e.Numero2;
                break;
            case '*':
                result = e.Numero1 * e.Numero2;
                break;
            case '/':
                if (e.Numero2 == 0)
                {
                    Console.WriteLine("Error: División por cero.");
                    return;
                }
                result = (float)e.Numero1 / e.Numero2;
                break;
            default:
                Console.WriteLine("Operador no válido.");
                return;
        }

        // Mostrar el resultado de la operación
        Console.WriteLine(e.Numero1 + " " + e.Operador + " " + e.Numero2 + " = " + result);
    }
   
}

class Program
{
    static void Main()
    {

        Publicador publicador = new Publicador();
        Suscriptor suscriptor = new Suscriptor();
        int n1, n2;
        char oper;
        // Suscripción del manejador de eventos
        publicador.EventoOcurrido += suscriptor.ManejadorEvento;


        
        do
        {
           
          
             
            
               
                    Console.WriteLine("ingrese un numero o 0 para salir ");
                    n1 = int.Parse(Console.ReadLine());
                    Console.WriteLine("ingrese un operador +,-,*,/");
           
                    oper = char.Parse(Console.ReadLine());

                   Console.WriteLine("ingrese un segundo numero");
                   n2 = int.Parse(Console.ReadLine());
                  publicador.DispararEvento( n1, n2,oper);
            
                    







            
          

        } while (n1!= 0);



        // Disparo del evento con diferentes números


    }
}
