using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PGE_E9_CALC
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int memori = 0;
        int aux = 0;
        string operacion = ".";
        string aux_cls;

        private void button17_Click(object sender, EventArgs e)
        {
            label1.Text += "0";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label1.Text += "1";
        }
        private void button2_Click(object sender, EventArgs e)
        {
            label1.Text += "2";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label1.Text += "3";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            label1.Text += "4";
        }
        private void button5_Click(object sender, EventArgs e)
        {
            label1.Text += "5";
        }
        private void button7_Click(object sender, EventArgs e)
        {
            label1.Text += "6";
        }

        private void button8_Click(object sender, EventArgs e)
        {
            label1.Text += "7";
        }

        private void button9_Click(object sender, EventArgs e)
        {
            label1.Text += "8";
        }

        private void button10_Click(object sender, EventArgs e)
        {
            label1.Text += "9";
        }

        private void button13_Click(object sender, EventArgs e)
        {
            memori = Convert.ToInt32(label1.Text);
            operacion = "+";
            label1.Text = "0";
            label3.Text = Convert.ToString(memori) + "+";

        }

        private void button14_Click(object sender, EventArgs e)
        {
            memori = Convert.ToInt32(label1.Text);
            operacion = "-";
            label1.Text = "0";
            label3.Text = Convert.ToString(memori) + "-";
        }

        private void button15_Click(object sender, EventArgs e)
        {
            memori = Convert.ToInt32(label1.Text);
            operacion = "*";
            label1.Text = "0";
            label3.Text = Convert.ToString(memori) + "*";
        }

        private void button16_Click(object sender, EventArgs e)
        {
            memori = Convert.ToInt32(label1.Text);
            operacion = "/";
            label1.Text = "0";
            label3.Text = Convert.ToString(memori) + "/";
        }

        private void button6_Click(object sender, EventArgs e)
        {
            aux = Convert.ToInt32(label1.Text);
            switch(operacion)
            {
                case "+":
                    label1.Text = Convert.ToString(memori + aux);
                    break;
                case "-":
                    label1.Text = Convert.ToString(memori - aux);
                    break;
                case "*":
                    label1.Text = Convert.ToString(memori * aux);
                    break;
                case "/":
                    try
                    {
                        label1.Text = Convert.ToString(memori / aux);
                    }
                    catch (DivideByZeroException)
                    {
                        MessageBox.Show("No se puede dividir por cero");
                    }
                    break;
            }
            aux = 0;
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button12_Click(object sender, EventArgs e)
        {
            aux_cls = label1.Text;

            if (!string.IsNullOrEmpty(aux_cls))
            {
                aux_cls = aux_cls.Substring(0, aux_cls.Length - 1);
            }

            label1.Text = aux_cls;
        }

        private void button11_Click(object sender, EventArgs e)
        {
            label1.Text = "0";
            memori = 0;
            aux = 0;
            label3.Text = "";
        }
    }
}
