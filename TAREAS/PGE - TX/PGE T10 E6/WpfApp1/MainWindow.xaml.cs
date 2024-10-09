using Microsoft.Win32;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using static System.Net.Mime.MediaTypeNames;

namespace WpfApp1
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

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog
            {
                Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif"
            };

            if (openFileDialog.ShowDialog() == true)
            {
                BitmapImage bitmap = new BitmapImage(new Uri(openFileDialog.FileName));
                imagen.Source = bitmap; 
            }
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            double ntam = tam.Value;
            double nb = brillo.Value;

            // Ajustar tamaño
            imagen.Height = ntam / 2;
            imagen.Width = ntam;

            // Ajustar brillo
            AdjustBrightness(nb);
        }

        private void AdjustBrightness(double brightness)
        {
            if (imagen.Source is BitmapSource bitmapSource)
            {
                int width = bitmapSource.PixelWidth;
                int height = bitmapSource.PixelHeight;

                // Crear un WriteableBitmap
                WriteableBitmap writableBitmap = new WriteableBitmap(bitmapSource);

                // Lock the bitmap's bits.
                writableBitmap.Lock();

                // Obtener el tamaño de los píxeles
                int bytesPerPixel = (writableBitmap.Format.BitsPerPixel + 7) / 8;
                int stride = writableBitmap.BackBufferStride;

                // Crear un buffer para almacenar los datos de los píxeles
                byte[] pixels = new byte[height * stride];
                Marshal.Copy(writableBitmap.BackBuffer, pixels, 0, pixels.Length);

                // Recorrer cada píxel y ajustar el brillo
                for (int y = 0; y < height; y++)
                {
                    for (int x = 0; x < width; x++)
                    {
                        int index = y * stride + x * bytesPerPixel;

                        // Ajustar el brillo
                        pixels[index] = (byte)Math.Min(255, pixels[index] * brightness);         // R
                        pixels[index + 1] = (byte)Math.Min(255, pixels[index + 1] * brightness); // G
                        pixels[index + 2] = (byte)Math.Min(255, pixels[index + 2] * brightness); // B
                    }
                }

                // Copiar los datos modificados de nuevo al WriteableBitmap
                Marshal.Copy(pixels, 0, writableBitmap.BackBuffer, pixels.Length);

                // Unlock the bitmap's bits.
                writableBitmap.Unlock();

                imagen.Source = writableBitmap;
            }
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog
            {
                Filter = "Image Files|*.jpg;*.png;*.bmp"
            };

            if (saveFileDialog.ShowDialog() == true)
            {
                BitmapEncoder encoder = new PngBitmapEncoder();
                encoder.Frames.Add(BitmapFrame.Create((BitmapSource)imagen.Source));

                using (var stream = new FileStream(saveFileDialog.FileName, FileMode.Create))
                {
                    encoder.Save(stream);
                }
            }
        }

        private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {

        }

        private void brillo_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {

        }
    }
}