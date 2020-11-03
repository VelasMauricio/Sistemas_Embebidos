using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.IO.Ports;
using System.Windows.Forms;

namespace Encendiendo_led
{
    public partial class Form1 : Form
    {
        String dato;
        public Form1()
        {
            InitializeComponent();
            //serialPort1.Open();
            //CheckForIllegalCrossThreadCalls = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("A");
         
        }

        private void button2_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("B");
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            CheckForIllegalCrossThreadCalls = false;
            dato = serialPort1.ReadLine();
            double numero = Convert.ToDouble(dato);
            double voltaje = Math.Round(((numero /1024) *5000), 2);
            double Temp = voltaje / 10;

            textBox1.Text = Convert.ToString(Temp);

            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("C");
        }

        private void button6_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("D");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("E");
        }

        private void button7_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("F");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("G");
        }

        private void button8_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("H");
        }

        private void button9_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("I");
        }

        private void button10_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("J");
        }

        private void button11_Click(object sender, EventArgs e)
        {
            serialPort1.PortName = txtSerie.Text;
            serialPort1.BaudRate = Convert.ToInt32(txtVelocidad.Text);
            serialPort1.Open();
        }

        private void button12_Click(object sender, EventArgs e)
        {
            serialPort1.Close();
        }

        private void button13_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("K");
        }
    }
}
