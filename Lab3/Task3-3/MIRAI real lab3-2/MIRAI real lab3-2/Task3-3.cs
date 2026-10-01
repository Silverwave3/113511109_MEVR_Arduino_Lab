using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace MIRAI_real_lab3_2
{
    public partial class Form1 : Form
    {
        // 1. 宣告移入 class 內部
        SerialPort mySerialPort;

        public Form1()
        {
            InitializeComponent();
            mySerialPort = new SerialPort("COM8", 9600);
            mySerialPort.DtrEnable = true;

            // 2. 將開啟通訊埠的邏輯放入建構式的方法內部
            try
            {
                mySerialPort.Open(); // 開啟序列埠
            }
            catch (Exception ex)
            {
                MessageBox.Show("無法開啟序列埠: " + ex.Message);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {


        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            if (mySerialPort != null && mySerialPort.IsOpen)
            {
                mySerialPort.WriteLine("ON");
            }
        }

        // 關閉應用程式時務必關閉序列埠釋放資源
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (mySerialPort != null && mySerialPort.IsOpen)
            {
                mySerialPort.Close();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (mySerialPort != null && mySerialPort.IsOpen)
            {
                mySerialPort.WriteLine("OFF");
            }
        }

        private void Form1_Load_1(object sender, EventArgs e)
        {

        }
    }
}