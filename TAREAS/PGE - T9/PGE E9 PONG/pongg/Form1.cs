using System;
using System.Drawing;
using System.Windows.Forms;
using System.Collections.Generic;
using static System.Formats.Asn1.AsnWriter;

namespace pongg
{
    public partial class Form1 : Form
    {
        private System.Windows.Forms.Timer timer;
        int pu1;
        int pu2;
        private int ballSpeedX = 5; // Velocidad en el eje X
        private int ballSpeedY = 5; // Velocidad en el eje Y
        private HashSet<Keys> keysPressed = new HashSet<Keys>();
        private Image backgroundImage;
        public Form1()
        {
            InitializeComponent();
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox2.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox3.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox3.Size = new Size(20, 20); // Ajusta el tamaño según necesites
            pictureBox3.Location = new Point(this.ClientSize.Width / 2, this.ClientSize.Height / 2);

            this.KeyPreview = true; // Habilitar la captura de teclas en el formulario
            this.KeyDown += new KeyEventHandler(Form1_KeyDown);
            this.KeyUp += new KeyEventHandler(Form1_KeyUp);

            InitializeTimer(); // Inicializar el temporizador para mover la pelota
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            if (backgroundImage != null)
            {
                e.Graphics.DrawImage(backgroundImage, 0, 0, this.ClientSize.Width, this.ClientSize.Height); // Dibuja la imagen de fondo
            }
        }
        private void InitializeTimer()
        {
            timer = new System.Windows.Forms.Timer();
            timer.Interval = 20; // Intervalo en milisegundos
            timer.Tick += new EventHandler(MoveBall);
            timer.Start();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (!keysPressed.Contains(e.KeyCode))
            {
                keysPressed.Add(e.KeyCode);
            }
            MovePictureBoxes();
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            if (keysPressed.Contains(e.KeyCode))
            {
                keysPressed.Remove(e.KeyCode);
            }
        }

        private void MovePictureBoxes()
        {
            // Mover pictureBox1
            if (keysPressed.Contains(Keys.W) && pictureBox1.Location.Y > 0)
            {
                pictureBox1.Location = new Point(pictureBox1.Location.X, pictureBox1.Location.Y - 20);
            }
            if (keysPressed.Contains(Keys.S) && pictureBox1.Location.Y < this.ClientSize.Height - pictureBox1.Height)
            {
                pictureBox1.Location = new Point(pictureBox1.Location.X, pictureBox1.Location.Y + 20);
            }

            // Mover pictureBox2
            if (keysPressed.Contains(Keys.Up) && pictureBox2.Location.Y > 0)
            {
                pictureBox2.Location = new Point(pictureBox2.Location.X, pictureBox2.Location.Y - 20);
            }
            if (keysPressed.Contains(Keys.Down) && pictureBox2.Location.Y < this.ClientSize.Height - pictureBox2.Height)
            {
                pictureBox2.Location = new Point(pictureBox2.Location.X, pictureBox2.Location.Y + 20);
            }
        }

        private void MoveBall(object sender, EventArgs e)
        {
            pictureBox3.Location = new Point(pictureBox3.Location.X + ballSpeedX, pictureBox3.Location.Y + ballSpeedY);

            // Colisiones con los bordes del formulario
            if (pictureBox3.Location.X <= 0)
            {
                // Aumentar puntaje del jugador 2
                pu2++;
                puntage2.Text = pu2.ToString(); // Actualiza la etiqueta del jugador 2

                // Reposicionar en el centro
                pictureBox3.Location = new Point(this.ClientSize.Width / 2 - pictureBox3.Width / 2, this.ClientSize.Height / 2 - pictureBox3.Height / 2);
            }
            if (pictureBox3.Location.X >= this.ClientSize.Width - pictureBox3.Width)
            {
                // Aumentar puntaje del jugador 1
                pu1++;
                puntage1.Text = pu1.ToString(); // Actualiza la etiqueta del jugador 1

                // Reposicionar en el centro
                pictureBox3.Location = new Point(this.ClientSize.Width / 2 - pictureBox3.Width / 2, this.ClientSize.Height / 2 - pictureBox3.Height / 2);
            }
            if (pictureBox3.Location.Y <= 0 || pictureBox3.Location.Y >= this.ClientSize.Height - pictureBox3.Height)
            {
                ballSpeedY = -ballSpeedY; // Rebota en el eje Y
            }

            // Verificar colisión con los jugadores
            if (IsColliding(pictureBox3, pictureBox1) || IsColliding(pictureBox3, pictureBox2))
            {
                ballSpeedX = -ballSpeedX; // Rebote en el eje X
            }
        }


        private bool IsColliding(Control a, Control b)
        {
            Rectangle rectA = new Rectangle(a.Location, a.Size);
            Rectangle rectB = new Rectangle(b.Location, b.Size);
            return rectA.IntersectsWith(rectB);
        }
    }
}