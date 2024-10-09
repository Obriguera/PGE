using System;
using System.Windows;

namespace TemperatureConverter
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void ConvertButton_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                
                double celsius = double.Parse(txtCelsius.Text);

                
                double fahrenheit = (celsius * 9 / 5) + 32;

                
                lblResult.Content = $"{celsius} °C = {fahrenheit} °F";
            }
            catch (FormatException)
            {
                
                lblResult.Content = "Porfavor ingrese un valor numerico.";
            }
        }
    }
}
