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

namespace CalculadoraConWPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        int aux, aux2;
        int rta;
        char ope;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Label1.Content += "0";
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            Label1.Content += "1";
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            Label1.Content += "2";
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            Label1.Content += "3";
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            Label1.Content += "4";
        }

        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            Label1.Content += "5";
        }

        private void Button_Click_6(object sender, RoutedEventArgs e)
        {
            Label1.Content += "6";
        }

        private void Button_Click_7(object sender, RoutedEventArgs e)
        {
            Label1.Content += "7";
        }

        private void Button_Click_8(object sender, RoutedEventArgs e)
        {
            Label1.Content += "8";
        }

        private void Button_Click_9(object sender, RoutedEventArgs e)
        {
            Label1.Content += "9";
        }

        private void Button_Click_10(object sender, RoutedEventArgs e)
        {
            aux = int.Parse(Label1.Content.ToString());
            ope = '%';
            Label1.Content = "0";
        }

        private void Button_Click_11(object sender, RoutedEventArgs e)
        {
            aux = int.Parse(Label1.Content.ToString());
            ope = 'x';
            Label1.Content = "0";
        }

        private void Button_Click_12(object sender, RoutedEventArgs e)
        {
            aux = int.Parse(Label1.Content.ToString());
            ope = '+';
            Label1.Content = "0";
        }

        private void Button_Click_13(object sender, RoutedEventArgs e)
        {
            aux = int.Parse(Label1.Content.ToString());
            ope = '-';
            Label1.Content = "0";
        }

        private void Button_Click_15(object sender, RoutedEventArgs e)
        {
            Label1.Content = "0";
            aux = 0;
            aux2 = 0;
            rta = 0;
        }

        private void Button_Click_14(object sender, RoutedEventArgs e)
        {
            if (aux2 == 0) // Esto solo será cierto la primera vez que presiones el igual
            {
                aux2 = int.Parse(Label1.Content.ToString());
            }

            switch (ope)
            {
                case '+':
                    rta = aux + aux2;
                    break;
                case '-':
                    rta = aux - aux2;
                    break;
                case 'x':
                    rta = aux * aux2;
                    break;
                case '%':
                    if (aux2 == 0)
                    {
                        MessageBox.Show("No se puede dividir entre 0");
                        return; 
                    }
                    rta = aux / aux2;
                    break;
            }

            Label1.Content = rta.ToString();
            aux = rta; 
        }

    }
}
