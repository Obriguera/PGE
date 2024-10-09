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

namespace PGE_T10_E7
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            
        }
        int adiviname = 0;
        int state = 0;
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if (state == 0)
            { 
                if (int.TryParse(IngresoNumero.Text, out int ingresoNumero) && ingresoNumero == adiviname)
                {
                    LabelPistas.Content = "¡Felicidades! Adivinaste el número.";
                    state = 1;
                }
                else if (ingresoNumero < adiviname)
                {
                    LabelPistas.Content = "El número es mayor.";
                }
                else if (ingresoNumero > adiviname)
                {
                    LabelPistas.Content = "El número es menor.";
                }
                else
                {
                    LabelPistas.Content = "Ingresa un número válido.";
                }
            }
            else
            {
                LabelPistas.Content = "Ya adivinaste el número. Reinicia el juego";
            }
        }

        private void BotonReinicar_Click(object sender, RoutedEventArgs e)
        {
            LabelPistas.Content = "Pista: -";
            Random random = new Random();
            adiviname = random.Next(1, 101);
            state = 0;
        }
    }
}
