using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media.Imaging;
using System.ComponentModel;
using System.Windows.Media;
using System.Windows.Data;
using System.Windows.Media.Animation;

namespace Ejercicio10
{
    public partial class MainWindow : Window
    {
        private Dictionary<string, List<Producto>> productos;

        public MainWindow()
        {
            InitializeComponent();

            productos = new Dictionary<string, List<Producto>>
            {
                { "Burger", new List<Producto>
                    {
                        new Producto {
                            Nombre = "Classic Burger",
                            Imagen = "pack://application:,,,/Recursos/Burger.png",
                            Descripcion = "La hamburguesa clásica, hecha con carne de res jugosa y todos los ingredientes tradicionales: Carne de res, lechuga, tomate, cebolla, pepinillos, queso cheddar, mayonesa, kétchup, y mostaza.",
                            Calificacion = 3
                        },
                        new Producto {
                            Nombre = "Bacon Cheeseburger",
                            Imagen = "pack://application:,,,/Recursos/Burger.png",
                            Descripcion = "Una deliciosa hamburguesa con bacon crujiente y queso fundido: Carne de res, bacon crujiente, queso cheddar, lechuga, tomate, cebolla caramelizada, mayonesa, kétchup.",
                            Calificacion = 4
                        },
                        new Producto {
                            Nombre = "BBQ Burger",
                            Imagen = "pack://application:,,,/Recursos/Burger.png",
                            Descripcion = "Una hamburguesa con un toque ahumado, ideal para los amantes de la salsa barbacoa: Carne de res, queso cheddar, cebolla frita, lechuga, tomate, salsa barbacoa, pepinillos.",
                            Calificacion = 5
                        }
                    }
                },
                { "Pizza", new List<Producto>
                    {
                        new Producto {
                            Nombre = "Pepperoni Pizza",
                            Imagen = "pack://application:,,,/Recursos/Pizza.png",
                            Descripcion = "Clásica pizza con abundante pepperoni y queso mozzarella fundido: Masa de pizza, salsa de tomate, pepperoni, queso mozzarella, orégano",
                            Calificacion = 5
                        },
                        new Producto {
                            Nombre = "Margherita Pizza",
                            Imagen = "pack://application:,,,/Recursos/Pizza.png",
                            Descripcion = "Una pizza simple pero deliciosa con queso mozzarella fresco y albahaca: Masa de pizza, salsa de tomate, queso mozzarella fresco, albahaca, aceite de oliva.",
                            Calificacion = 4
                        },
                        new Producto {
                            Nombre = "Hawaiana Pizza",
                            Imagen = "pack://application:,,,/Recursos/Pizza.png",
                            Descripcion = "Una combinación dulce y salada, con piña y jamón: Masa de pizza, salsa de tomate, queso mozzarella, piña, jamón, orégano.",
                            Calificacion = 3
                        },
                    }
                },
                { "Dessert", new List<Producto>
                    {
                        new Producto {
                            Nombre = "Cupcake de Higos",
                            Imagen = "pack://application:,,,/Recursos/Desserts.png",
                            Descripcion = "Un esponjoso cupcake de vainilla cubierto con glaseado e higos: Harina, manteca, azúcar, huevos, extracto de vainilla, leche, glaseado de crema e higos frescos.",
                            Calificacion = 5
                        },
                        new Producto {
                            Nombre = "Cheesecake de Frutilla",
                            Imagen = "pack://application:,,,/Recursos/Desserts.png",
                            Descripcion = "Suave tarta de queso con una capa dulce de frutillas frescas: Queso crema, galletas molidas, manteca, frutillas, azúcar, crema batida.",
                            Calificacion = 4
                        },
                        new Producto {
                            Nombre = "Chocolate Brownie",
                            Imagen = "pack://application:,,,/Recursos/Desserts.png",
                            Descripcion = "Un denso y delicioso brownie de chocolate, perfecto para los amantes del chocolate: Chocolate oscuro, manteca, azúcar, huevos, harina, nueces (opcional).",
                            Calificacion = 4
                        },
                    }
                },
                { "French", new List<Producto>
                    {
                        new Producto {
                            Nombre = "Papas Fritas Clásicas",
                            Imagen = "pack://application:,,,/Recursos/Fries.png",
                            Descripcion = "Papas fritas doradas y crujientes, acompañadas de una pizca de sal: Papas, aceite vegetal, sal.",
                            Calificacion = 4
                        },
                        new Producto {
                            Nombre = "Papas con Cheddar",
                            Imagen = "pack://application:,,,/Recursos/Fries.png",
                            Descripcion = "Papas fritas bañadas en una rica salsa de queso cheddar: Papas, aceite vegetal, queso cheddar, crema de leche, sal.",
                            Calificacion = 5
                        },
                        new Producto {
                            Nombre = "Papas Bravas",
                            Imagen = "pack://application:,,,/Recursos/Fries.png",
                            Descripcion = "Papas fritas crujientes cubiertas con una salsa picante especial: Papas, aceite vegetal, salsa brava (tomate, ajo, pimentón, guindilla), sal.",
                            Calificacion = 4
                        }
                    }
                },
                { "Drinks", new List<Producto>
                    {
                        new Producto {
                            Nombre = "Limonada de Frutas Tropicales",
                            Imagen = "pack://application:,,,/Recursos/Drink.png",
                            Descripcion = "Refrescante combinación de jugo de limón con un toque de piña y mango: Jugo de limón, jugo de piña, jugo de mango, agua, azúcar, hielo.",
                            Calificacion = 4
                        },
                        new Producto {
                            Nombre = "Mojito Sin Alcohol",
                            Imagen = "pack://application:,,,/Recursos/Drink.png",
                            Descripcion = "Refrescante mezcla de menta y lima con un toque de agua con gas: Hojas de menta, jugo de lima, azúcar, agua con gas, hielo.",
                            Calificacion = 5
                        },
                        new Producto {
                            Nombre = "Té Verde con Miel y Jengibre",
                            Imagen = "pack://application:,,,/Recursos/Drink.png",
                            Descripcion = "Una combinación energizante de té verde con un toque de jengibre fresco y miel: Té verde, jengibre fresco, miel, limón, agua caliente.",
                            Calificacion = 3
                        }
                    }
                },
                { "Chinese", new List<Producto>
                    {
                        new Producto {
                            Nombre = "Kung Pao Chicken",
                            Imagen = "pack://application:,,,/Recursos/Chinese.png",
                            Descripcion = "Pollo salteado con cacahuates y una salsa picante, un plato clásico de la cocina Sichuan: Pollo, cacahuates, pimientos, cebolla, salsa de soja, vinagre de arroz, ajo, jengibre, chile seco.",
                            Calificacion = 3
                        },
                        new Producto {
                            Nombre = "Arroz Frito con Vegetales",
                            Imagen = "pack://application:,,,/Recursos/Chinese.png",
                            Descripcion = "Arroz salteado con una mezcla de vegetales frescos: Arroz blanco, zanahorias, guisantes, pimientos, cebolla, salsa de soja, huevo.",
                            Calificacion = 4
                        },
                        new Producto {
                            Nombre = "Pollo a la Naranja",
                            Imagen = "pack://application:,,,/Recursos/Chinese.png",
                            Descripcion = "Crujiente pollo frito cubierto con una salsa agridulce de naranja, perfecto para los amantes de los sabores cítricos: Pollo, salsa de soja, jengibre, ajo, jugo de naranja, azúcar, vinagre de arroz, almidón de maíz, cáscara de naranja, chile rojo.",
                            Calificacion = 5
                        }
                    }
                }
            };

            MostrarProductosConMayorPuntaje();
        }

        private void BtnCategoria_Click(object sender, RoutedEventArgs e)
        {
            Button botonClicado = sender as Button;

            if (botonClicado != null)
            {
                string categoria = botonClicado.Name.Substring(3);

                if (productos.ContainsKey(categoria))
                {
                    itemsControlProductos.ItemsSource = productos[categoria];

                    // Ocultar productos destacados y mapa
                    Storyboard hideMapAndHighlightsStoryboard = (Storyboard)this.FindResource("HideMapAndHighlightsStoryboard");
                    hideMapAndHighlightsStoryboard.Begin();
                }
            }
        }

        private void BtnVolver_Click(object sender, RoutedEventArgs e)
        {
            Storyboard showMapAndHighlightsStoryboard = (Storyboard)this.FindResource("ShowMapAndHighlightsStoryboard");
            showMapAndHighlightsStoryboard.Begin();

            // Llamar al método para asegurar que solo se muestren los dos productos seleccionados.
            MostrarProductosConMayorPuntaje();
        }
        private void MostrarProductosConMayorPuntaje()
        {
            var topProductos = new List<Producto>();

            // Limpiar los productos destacados antes de actualizar
            itemsControlTopProductos.ItemsSource = null;

            // Obtener el producto con mayor calificación de la categoría "Burger"
            if (productos.ContainsKey("Burger"))
            {
                var topBurger = productos["Burger"].OrderByDescending(p => p.Calificacion).FirstOrDefault();
                if (topBurger != null)
                {
                    topProductos.Add(topBurger);
                }
            }

            // Obtener el producto con mayor calificación de la categoría "Pizza"
            if (productos.ContainsKey("Pizza"))
            {
                var topPizza = productos["Pizza"].OrderByDescending(p => p.Calificacion).FirstOrDefault();
                if (topPizza != null)
                {
                    topProductos.Add(topPizza);
                }
            }

            // Limitar a los dos productos de mayor puntaje
            topProductos = topProductos.Take(2).ToList();

            // Asignar los productos actualizados al ItemsControl
            itemsControlTopProductos.ItemsSource = topProductos;
        }

    }

    public class Producto : INotifyPropertyChanged
    {
        public string Nombre { get; set; }
        public string Imagen { get; set; }
        public string Descripcion { get; set; }

        private int _calificacion;
        public int Calificacion
        {
            get { return _calificacion; }
            set
            {
                if (_calificacion != value)
                {
                    _calificacion = value;
                    OnPropertyChanged(nameof(Calificacion));
                }
            }
        }

        public ICommand RateCommand => new RelayCommand<int>(Rate);

        private void Rate(int rating)
        {
            Calificacion = rating;
        }

        public event PropertyChangedEventHandler PropertyChanged;
        protected void OnPropertyChanged(string name)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
        }
    }

    public class RelayCommand<T> : ICommand
    {
        private readonly Action<T> _execute;

        public RelayCommand(Action<T> execute)
        {
            _execute = execute;
        }

        public bool CanExecute(object parameter) => true;

        public void Execute(object parameter)
        {
            if (parameter is T param)
            {
                _execute(param);
            }
        }

        public event EventHandler CanExecuteChanged;
    }

    public class StarColorConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            int calificacion = (int)value;
            int estrella = int.Parse(parameter.ToString());

            return calificacion >= estrella ? Brushes.Gold : Brushes.Gray;
        }

        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
