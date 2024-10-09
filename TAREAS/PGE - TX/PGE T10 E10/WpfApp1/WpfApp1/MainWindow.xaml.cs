using System;
using System.Globalization;
using System.Windows;
using System.Windows.Controls;

namespace ConversorUnidades
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void ConvertButton_Click(object sender, RoutedEventArgs e)
        {
            if (!double.TryParse(txtValue.Text, NumberStyles.Any, CultureInfo.InvariantCulture, out double value))
            {
                MessageBox.Show("Por favor, ingrese un número válido.", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }

            string fromUnit = (cmbFromUnit.SelectedItem as ComboBoxItem)?.Content.ToString();
            string toUnit = (cmbToUnit.SelectedItem as ComboBoxItem)?.Content.ToString();

            if (fromUnit == null || toUnit == null)
            {
                MessageBox.Show("Por favor, seleccione las unidades de origen y destino.", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }

            
            double result = ConvertUnits(value, fromUnit, toUnit);
            txtResult.Text = $"{value} {fromUnit} = {result} {toUnit}";
        }

        private double ConvertUnits(double value, string fromUnit, string toUnit)
        {
            double meters = 0;

            if (fromUnit == "Metros")
            {
                meters = value;
            }
            else if (fromUnit == "Kilómetros")
            {
                meters = value * 1000;
            }
            else if (fromUnit == "Gramos")
            {
                meters = value; 
            }
            else if (fromUnit == "Kilogramos")
            {
                meters = value * 1000;
            }

            
            if (toUnit == "Metros")
            {
                return meters;
            }
            else if (toUnit == "Kilómetros")
            {
                return meters / 1000;
            }
            else if (toUnit == "Gramos")
            {
                return meters; 
            }
            else if (toUnit == "Kilogramos")
            {
                return meters / 1000;
            }

            throw new InvalidOperationException("Unidad de conversión no soportada.");
        }
    }
}
