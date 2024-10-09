using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Shapes;

namespace SimpleDrawingApp
{
    public partial class MainWindow : Window
    {
        private bool isDrawing = false;
        private Line currentLine;

        public MainWindow()
        {
            InitializeComponent();
        }

        
        private void drawingCanvas_MouseDown(object sender, MouseButtonEventArgs e)
        {
            isDrawing = true;

            
            currentLine = new Line
            {
                Stroke = GetSelectedColor(),
                StrokeThickness = thicknessSlider.Value,
                X1 = e.GetPosition(drawingCanvas).X,
                Y1 = e.GetPosition(drawingCanvas).Y,
                X2 = e.GetPosition(drawingCanvas).X,
                Y2 = e.GetPosition(drawingCanvas).Y
            };
            drawingCanvas.Children.Add(currentLine);
        }

        private void drawingCanvas_MouseMove(object sender, MouseEventArgs e)
        {
            if (isDrawing)
            {
              
                currentLine.X2 = e.GetPosition(drawingCanvas).X;
                currentLine.Y2 = e.GetPosition(drawingCanvas).Y;
            }
        }

        
        private void drawingCanvas_MouseUp(object sender, MouseButtonEventArgs e)
        {
            isDrawing = false;
        }

        
        private SolidColorBrush GetSelectedColor()
        {
            string selectedColor = (colorPicker.SelectedItem as ComboBoxItem)?.Content.ToString();

            if (selectedColor == "Red")
            {
                return Brushes.Red;
            }
            else if (selectedColor == "Green")
            {
                return Brushes.Green;
            }
            else if (selectedColor == "Blue")
            {
                return Brushes.Blue;
            }
            else
            {
                return Brushes.Black;
            }
        }

        private void colorPicker_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }
    }
}
