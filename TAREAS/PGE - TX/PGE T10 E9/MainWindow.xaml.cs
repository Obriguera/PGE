using Microsoft.Win32; // Necesario para el OpenFileDialog
using System;
using System.IO; // Para trabajar con archivos
using System.Windows;

namespace PGE_T10_E9
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Botonaso_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Archivos de texto (*.txt)|*.txt"; // Filtrar solo archivos de texto

            if (openFileDialog.ShowDialog() == true) // Si el usuario selecciona un archivo y hace clic en OK
            {
                string filePath = openFileDialog.FileName; // Obtener la ruta del archivo
                displayTextBox.Text = File.ReadAllText(filePath); // Leer el archivo y mostrar su contenido en el TextBox
            }
        }
    }
}
