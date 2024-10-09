using OxyPlot.Series;
using OxyPlot;
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
using OxyPlot.Axes;

namespace PGE_T10_E4
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        private Dictionary<string, double> VentasPorMes = new Dictionary<string, double>
        {
            { "Enero", 5000},
            { "Febrero", 7000 },
            { "Marzo", 8000 },
            { "DICIEMBRE", 10000 },
            // Agrega más meses y valores de ventas aquí
        };

        public MainWindow()
        {
            InitializeComponent();
            ActualizarGrafico("Enero");

        }
        // Evento para actualizar el gráfico cuando se selecciona un mes
        private void MesComboBox_SelectionChanged(object sender, System.Windows.Controls.SelectionChangedEventArgs e)
        {
            var comboBoxItem = MesComboBox.SelectedItem as System.Windows.Controls.ComboBoxItem;
            if (comboBoxItem != null)
            {
                string mesSeleccionado = comboBoxItem.Content.ToString();
                ActualizarGrafico(mesSeleccionado);
            }
        }


        // Evento para actualizar el gráfico cuando se hace clic en el botón
        private void ActualizarGraficoButton_Click(object sender, RoutedEventArgs e)
        {
            var comboBoxItem = MesComboBox.SelectedItem as System.Windows.Controls.ComboBoxItem;
            if (comboBoxItem != null)
            {
                string mesSeleccionado = comboBoxItem.Content.ToString();
                ActualizarGrafico(mesSeleccionado);
            }
        }

        // Función para crear y mostrar el gráfico de ventas
        private void ActualizarGrafico(string mesSeleccionado = null)
        {
            // Crear un nuevo modelo de gráfico
            var modeloGrafico = new PlotModel { Title = "Ventas Mensuales" };

            // Crear una serie de barras
            var serieBarras = new BarSeries
            {
                Title = "Ventas",
                LabelPlacement = LabelPlacement.Inside,
                LabelFormatString = "{0:C0}" // Formato de moneda
            };

            // Eje de categoría para los meses
            var categoriaEje = new CategoryAxis { Position = AxisPosition.Left };

            // Añadir los datos de ventas filtrados por mes seleccionado (si hay)
            if (mesSeleccionado != null && VentasPorMes.ContainsKey(mesSeleccionado))
            {
                // Mostrar solo el mes seleccionado
                serieBarras.Items.Add(new BarItem(VentasPorMes[mesSeleccionado]));
                categoriaEje.Labels.Add(mesSeleccionado);
            }
            else
            {
                // Mostrar todos los meses
                foreach (var venta in VentasPorMes.Reverse()) // Usar Reverse para invertir el orden
                {
                    serieBarras.Items.Add(new BarItem(venta.Value));
                    categoriaEje.Labels.Add(venta.Key); // Agregar los meses al eje
                }
            }

            // Añadir la serie y el eje al modelo
            modeloGrafico.Series.Add(serieBarras);
            modeloGrafico.Axes.Add(categoriaEje);

            // Establecer el modelo en el PlotView
            PlotViewGrafico.Model = modeloGrafico;
        }



    }
}
