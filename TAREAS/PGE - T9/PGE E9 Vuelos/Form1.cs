using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PGE_E9_Vuelos
{
    public partial class Form1 : Form
    {
        private List<Pasajero> pasajeros = new List<Pasajero>();
        private List<Vuelo> vuelos = new List<Vuelo>();
        private List<Reserva> reservas = new List<Reserva>();

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Agregar Pasajero
            string nombre = textBox1.Text;
            string apellido = textBox2.Text;
            string dni = textBox3.Text;

            // Verificar que el DNI sea un entero
            if (!string.IsNullOrWhiteSpace(nombre) &&
                !string.IsNullOrWhiteSpace(apellido) &&
                !string.IsNullOrWhiteSpace(dni) &&
                int.TryParse(dni, out _))
            {
                Pasajero pasajero = new Pasajero(nombre, apellido, dni);
                pasajeros.Add(pasajero); // Utiliza la lista global
                MessageBox.Show("Pasajero agregado con éxito.");
                textBox1.Clear();
                textBox2.Clear();
                textBox3.Clear();

                // Actualiza ComboBox de Pasajeros
                comboBox2.Items.Add(pasajero);
            }
            else
            {
                MessageBox.Show("Por favor, complete todos los campos correctamente y asegúrese de que el DNI contiene solo números.");
            }
        }


        private void button2_Click(object sender, EventArgs e)
        {
            // Agregar Vuelo
            string numeroVuelo = textBox4.Text;
            string destino = textBox5.Text;
            string origen = textBox6.Text;
            int asientosTotales;
            int asientosDisponibles;

            if (int.TryParse(textBox7.Text, out asientosTotales) &&
                int.TryParse(textBox8.Text, out asientosDisponibles) &&
                !string.IsNullOrWhiteSpace(numeroVuelo) &&
                !string.IsNullOrWhiteSpace(destino) &&
                !string.IsNullOrWhiteSpace(origen))
            {
                Vuelo vuelo = new Vuelo(numeroVuelo, destino, origen, asientosTotales);
                vuelo.AsientosDisponibles = asientosDisponibles;

                // Suscribir el evento ErrorReserva para manejar errores de reserva
                vuelo.ErrorReserva += ManejarErrorReserva;

                vuelos.Add(vuelo);
                MessageBox.Show("Vuelo agregado con éxito.");
                textBox4.Clear();
                textBox5.Clear();
                textBox6.Clear();
                textBox7.Clear();
                textBox8.Clear();
                comboBox1.Items.Add(vuelo);
            }
            else
            {
                MessageBox.Show("Por favor, complete todos los campos del vuelo y asegúrese de que los asientos son números válidos.");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            // Agregar Reserva
            if (comboBox2.SelectedItem != null && comboBox1.SelectedItem != null)
            {
                var pasajeroSeleccionado = comboBox2.SelectedItem as Pasajero;
                var vueloSeleccionado = comboBox1.SelectedItem as Vuelo;

                // Validar si hay asientos disponibles y que el número de asientos no exceda el total
                if (vueloSeleccionado.AsientosDisponibles > 0)
                {
                    int asiento = vueloSeleccionado.AsientosTotales - vueloSeleccionado.AsientosDisponibles + 1;

                    // Verificar si el número de asiento es consistente
                    if (asiento <= vueloSeleccionado.AsientosTotales)
                    {
                        vueloSeleccionado.AsientosDisponibles--;

                        // Crear y agregar la reserva
                        Reserva reserva = new Reserva(pasajeroSeleccionado, vueloSeleccionado, asiento);
                        reservas.Add(reserva); // Utiliza la lista global
                        MessageBox.Show("Reserva realizada con éxito.");
                    }
                    else
                    {
                        MessageBox.Show("Error: El número de asiento asignado excede el total de asientos del vuelo.");
                    }
                }
                else
                {
                    MessageBox.Show("No hay asientos disponibles en este vuelo.");
                }
            }
            else
            {
                MessageBox.Show("Seleccione un pasajero y un vuelo.");
            }
        }


        // Método para manejar errores de reserva
        private void ManejarErrorReserva(string mensaje)
        {
            MessageBox.Show(mensaje, "Error de Reserva");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            // Mostrar todo el contenido cargado
            string contenido = "Pasajeros:\n";
            foreach (var pasajero in pasajeros)
            {
                contenido += $"- {pasajero.Nombre} {pasajero.Apellido}, DNI: {pasajero.DNI}\n";
            }

            contenido += "\nVuelos:\n";
            foreach (var vuelo in vuelos)
            {
                contenido += $"- Vuelo {vuelo.NumeroVuelo}, Origen: {vuelo.Origen}, Destino: {vuelo.Destino}, Asientos Disponibles: {vuelo.AsientosDisponibles}\n";
            }

            contenido += "\nReservas:\n";
            foreach (var reserva in reservas)
            {
                contenido += $"- {reserva.Pasajero.Nombre} {reserva.Pasajero.Apellido} reservó asiento {reserva.Asiento} en vuelo {reserva.Vuelo.NumeroVuelo}\n";
            }

            MessageBox.Show(contenido, "Contenido Cargado");
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }
    }


    public class Pasajero
    {
        public string Nombre { get; set; }
        public string Apellido { get; set; }
        public string DNI { get; set; }

        public Pasajero(string nombre, string apellido, string dni)
        {
            Nombre = nombre;
            Apellido = apellido;
            DNI = dni;
        }

        public void MostrarInformacion()
        {
            Console.WriteLine($"Nombre: {Nombre}, Apellido: {Apellido}, DNI: {DNI}");
        }

        // Sobrescribe el método ToString para una mejor visualización en ComboBox
        public override string ToString()
        {
            return $"{Nombre} {Apellido}";
        }
    }

    public class Vuelo
    {

        public string NumeroVuelo { get; set; }
        public string Destino { get; set; }
        public string Origen { get; set; }
        public int AsientosTotales { get; set; }
        public int AsientosDisponibles { get; set; }

        // Definir un evento para manejar errores de reserva
        public event Action<string> ErrorReserva;

        public Vuelo(string numeroVuelo, string destino, string origen, int asientosTotales)
        {
            NumeroVuelo = numeroVuelo;
            Destino = destino;
            Origen = origen;
            AsientosTotales = asientosTotales;
            AsientosDisponibles = asientosTotales;
        }

        public void MostrarInformacion()
        {
            Console.WriteLine($"Vuelo: {NumeroVuelo}, Destino: {Destino}, Origen: {Origen}, Asientos Totales: {AsientosTotales}, Asientos Disponibles: {AsientosDisponibles}");
        }

        public bool ReservarAsiento()
        {
            if (AsientosDisponibles > 0)
            {
                AsientosDisponibles--;
                return true;
            }

            // Dispara el evento ErrorReserva si no hay asientos disponibles
            ErrorReserva?.Invoke($"No hay asientos disponibles en el vuelo {NumeroVuelo} de {Origen} a {Destino}.");
            return false;
        }

        // Sobrescribe el método ToString para una mejor visualización en ComboBox
        public override string ToString()
        {
            return $"Vuelo {NumeroVuelo} - {Origen} a {Destino}";
        }


    }

    public class Reserva
    {
        public Pasajero Pasajero { get; set; }
        public Vuelo Vuelo { get; set; }
        public int Asiento { get; set; }

        public Reserva(Pasajero pasajero, Vuelo vuelo, int asiento)
        {
            Pasajero = pasajero;
            Vuelo = vuelo;
            Asiento = asiento;
        }

        public void MostrarInformacion()
        {
            Console.WriteLine("Reserva para:");
            Pasajero.MostrarInformacion();
            Console.WriteLine($"Vuelo: {Vuelo.NumeroVuelo}, Asiento N°: {Asiento}");
        }
    }
}
