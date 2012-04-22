using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Kurb
{
    public partial class Form1 : Form
    {
        private bool is_receiving;
        private string line;

        public Form1()
        {
            is_receiving = false;

            InitializeComponent();
        }

        private void get_line_and_parse_it()
        {
                if (is_receiving)
                {
                    line = serialPort1.ReadLine();
                    if (line.Equals("T°"))
                    {
                        MessageBox.Show("coucou maman !\n");
                    }
                }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.Open();
                is_receiving = true;
            }
            catch (Exception)
            {
                MessageBox.Show("Cannot open port : " + comboBox1.Text + " \nPlease verify the connection and the port number !");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                String filename = ("logs\\"
              + DateTime.Now.Year.ToString() + "_"
              + DateTime.Now.Month.ToString() + "_"
              + DateTime.Now.Day.ToString() + "__"
              + DateTime.Now.Hour.ToString() + "h_"
              + DateTime.Now.Minute.ToString() + "m_"
              + DateTime.Now.Second.ToString() + "s__Serial_Log.rtf");

                if (System.IO.Directory.Exists("logs") == false)
                    System.IO.Directory.CreateDirectory("logs");
                richTextBox1.SaveFile(filename);
                MessageBox.Show("Log saved to : " + filename + " !");
            }
            catch (Exception)
            {
                MessageBox.Show("Unable to save log !\nCheck if you have free space on disc \n and have the write rights on the directory !");
            }
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            get_line_and_parse_it();
        }
    }
}
