using System;
using System.Drawing;
using System.Windows.Forms;

namespace tp5
{
    public partial class Form1 : Form
    {
        private string? originalImagePath;
        public Form1()
        {
            InitializeComponent();
            // Configura el modo de tamaño del PictureBox directamente
            image.SizeMode = PictureBoxSizeMode.StretchImage;
            trackBar1.Minimum = 1; // Tamaño mínimo
            trackBar1.Maximum = 150; // Tamaño máximo (200%)
            trackBar1.Value = 100; // Resetear tamaño al 100%
            trackBar2.Minimum = -100; // Brillo mínimo
            trackBar2.Maximum = 100; // Brillo máximo
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.InitialDirectory = "C:\\";
                openFileDialog.Filter = "Archivos de imagen (*.jpg, *.jpeg, *.png, *.bmp)|*.jpg;*.jpeg;*.png;*.bmp";
                openFileDialog.Title = "Seleccionar imagen";

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    // Liberar la imagen anterior si existe
                    if (image.Image != null)
                    {
                        image.Image.Dispose();
                    }

                    originalImagePath = openFileDialog.FileName;
                    // Cargar la imagen directamente en el PictureBox
                    image.Image = new Bitmap(openFileDialog.FileName);
                    trackBar1.Value = 100; // Resetear tamaño al 100%
                    trackBar2.Value = 0;
                }
            }
           
        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            // Aquí puedes agregar lógica para ajustar el brillo si lo necesitas.
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (image.Image != null)
            {
                // Calcular el nuevo tamaño basado en el valor del TrackBar
                int newSize = (int)(image.Image.Width * (trackBar1.Value / 100.0));

                // Asegurarse de que no exceda el tamaño máximo
                if (newSize > 644 || newSize > 301)
                {
                    newSize = Math.Min(644, 301); // Elegir el tamaño máximo
                }

                // Cambiar tamaño del PictureBox
                image.Size = new Size(newSize, newSize);

                // Obtener el valor de brillo del TrackBar
                float brightnessFactor = trackBar2.Value / 100.0f;

               
                Bitmap adjustedImage = AdjustBrightness((Bitmap)image.Image, brightnessFactor);

              
                image.Image = adjustedImage;
            }
            else
            {
                MessageBox.Show("No hay imagen para aplicar los cambios.");
            }
        }
        private Bitmap AdjustBrightness(Bitmap original, float brightness)
        {
          
            Bitmap newBitmap = new Bitmap(original.Width, original.Height);

          
            for (int y = 0; y < original.Height; y++)
            {
                for (int x = 0; x < original.Width; x++)
                {
                    Color originalColor = original.GetPixel(x, y);

                    
                    int r = Clamp((int)(originalColor.R * (1 + brightness)));
                    int g = Clamp((int)(originalColor.G * (1 + brightness)));
                    int b = Clamp((int)(originalColor.B * (1 + brightness)));

                    
                    newBitmap.SetPixel(x, y, Color.FromArgb(originalColor.A, r, g, b));
                }
            }

            return newBitmap;
        }

        private int Clamp(int value)
        {
            return Math.Max(0, Math.Min(255, value)); 
        }
        private void button3_Click(object sender, EventArgs e)
        {
            if (image.Image != null)
            {
                using (SaveFileDialog saveFileDialog = new SaveFileDialog())
                {
                    saveFileDialog.InitialDirectory = "C:\\";
                    saveFileDialog.Filter = "Archivos de imagen (*.jpg, *.jpeg, *.png, *.bmp)|*.jpg;*.jpeg;*.png;*.bmp";
                    saveFileDialog.Title = "Guardar imagen como";

                    if (saveFileDialog.ShowDialog() == DialogResult.OK)
                    {
                        // Guardar la imagen con el nombre y formato especificados
                        string filePath = saveFileDialog.FileName;
                        image.Image.Save(filePath);
                        MessageBox.Show("Imagen guardada exitosamente.");
                    }
                }
            }
            else
            {
                MessageBox.Show("No hay imagen para guardar.");
            }
        }
    }
}