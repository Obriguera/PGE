using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace PGE_T10_E3
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public List<Gasto> Gastos { get; set; }
        public MainWindow()
        {
            InitializeComponent();
            Gastos = new List<Gasto>();
            ListaGastos.ItemsSource = Gastos;

        }

        Dictionary<string,decimal> tasasDeConversion = new Dictionary<string, decimal>
        {
            { "Dolar", 1.0m },           // Referencia al dólar
            { "Euro", 0.85m },           // Ejemplo: 1 Dólar = 0.85 Euros
            { "Peso", 300m },            // Ejemplo: 1 Dólar = 300 Pesos
            { "Peso Ucraniano", 36.8m }  // Ejemplo: 1 Dólar = 36.8 UAH
        };

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if (ListaMonedas.SelectedItem == null)
            {
                MessageBox.Show("Por favor, seleccione una moneda.");
                return;
            }

            // Obtener la moneda seleccionada
            ComboBoxItem selectedItem = (ComboBoxItem)ListaMonedas.SelectedItem;
            string monedaSeleccionada = selectedItem.Content.ToString();

            if (monedaSeleccionada == "----")
            {
                MessageBox.Show("Por favor, seleccione una moneda válida.");
                return;
            }

            // Obtener la tasa de conversión
            if (!tasasDeConversion.TryGetValue(monedaSeleccionada, out decimal tasaDeCambio))
            {
                MessageBox.Show("No se encontró la tasa de conversión para la moneda seleccionada.");
                return;
            }

            // Sumar todos los costos de los gastos en la moneda seleccionada
            decimal totalConvertido = 0;
            foreach (var gasto in Gastos)
            {
                // Asumiendo que todos los costos están inicialmente en dólares (USD)
                decimal costoConvertido = gasto.Costo * tasaDeCambio;
                totalConvertido += costoConvertido;
            }

            // Mostrar el resultado en el Label o TextBlock
            TotalConvertido.Content = $"Total en {monedaSeleccionada}: {totalConvertido:F2}";

        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void ListaGastos_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void AgregarGasto_Click(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrWhiteSpace(Gastoss.Text) || string.IsNullOrWhiteSpace(Costo.Text) || ListaMonedas.SelectedItem == null)
            {
                MessageBox.Show("Por favor, complete todos los campos.");
                return;
            }

            if (!decimal.TryParse(Costo.Text, out decimal costo))
            {
                MessageBox.Show("El costo debe ser un número válido.");
                return;
            }

            var nuevaMoneda = (ListaMonedas.SelectedItem as ComboBoxItem).Content.ToString();
            Gastos.Add(new Gasto
            {
                Descripcion = Gastoss.Text,
                Costo = costo,
                Moneda = "---"
            });

            ListaGastos.Items.Refresh(); // Actualiza el DataGrid
        }

        public class Gasto
        {
            public string Descripcion { get; set; }
            public decimal Costo { get; set; }
            public string Moneda { get; set; }
        }

        private void ListaMonedas_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }
    }
}
