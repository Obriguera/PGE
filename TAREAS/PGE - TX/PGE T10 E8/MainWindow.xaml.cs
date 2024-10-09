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

namespace PGE_T10_E8
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        private decimal ACalcular;
        private string aux;
        private void BtnCalcular_Click(object sender, RoutedEventArgs e)
        {
            
            if (decimal.TryParse(TBMonto.Text, out ACalcular) && ACalcular > 0 && CBPorcentaje.SelectedItem != null)
            {
                
                string porcentajeSeleccionado = (CBPorcentaje.SelectedItem as ComboBoxItem).Content.ToString();

                
                if (porcentajeSeleccionado == "10%")
                {
                    ACalcular = ACalcular * 10 / 100;
                }
                else if (porcentajeSeleccionado == "15%")
                {
                    ACalcular = ACalcular * 15 / 100;
                }
                else if (porcentajeSeleccionado == "20%")
                {
                    ACalcular = ACalcular * 20 / 100;
                }
                else if (porcentajeSeleccionado == "25%")
                {
                    ACalcular = ACalcular * 25 / 100;
                }

                // Convertimos el resultado a string y lo mostramos
                aux = ACalcular.ToString("F2"); // Formato con 2 decimales
                LResultado.Content = "Resultado: " + aux;
            }
            else
            {
                MessageBox.Show("Por favor, ingrese un monto válido y seleccione un porcentaje.");
            }
        }


    }
}
