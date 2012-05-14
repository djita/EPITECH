namespace Kurb
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.comboBox6 = new System.Windows.Forms.ComboBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.comboBox5 = new System.Windows.Forms.ComboBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.comboBox3 = new System.Windows.Forms.ComboBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.comboBox2 = new System.Windows.Forms.ComboBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.button1 = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.button3 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.temperature_graph = new componentXtra.XYGraph();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.pot_graph = new componentXtra.XYGraph();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Location = new System.Drawing.Point(13, 13);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(876, 588);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.groupBox6);
            this.tabPage1.Controls.Add(this.groupBox5);
            this.tabPage1.Controls.Add(this.groupBox4);
            this.tabPage1.Controls.Add(this.groupBox2);
            this.tabPage1.Controls.Add(this.groupBox3);
            this.tabPage1.Controls.Add(this.button1);
            this.tabPage1.Controls.Add(this.groupBox1);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(868, 562);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Options";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.comboBox6);
            this.groupBox6.Location = new System.Drawing.Point(603, 509);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(143, 47);
            this.groupBox6.TabIndex = 6;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Data bits";
            // 
            // comboBox6
            // 
            this.comboBox6.FormattingEnabled = true;
            this.comboBox6.Items.AddRange(new object[] {
            "7",
            "8",
            "9"});
            this.comboBox6.Location = new System.Drawing.Point(6, 20);
            this.comboBox6.Name = "comboBox6";
            this.comboBox6.Size = new System.Drawing.Size(121, 21);
            this.comboBox6.TabIndex = 4;
            this.comboBox6.Text = "8";
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.comboBox5);
            this.groupBox5.Location = new System.Drawing.Point(454, 509);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(143, 47);
            this.groupBox5.TabIndex = 5;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Parity bits";
            // 
            // comboBox5
            // 
            this.comboBox5.FormattingEnabled = true;
            this.comboBox5.Items.AddRange(new object[] {
            "0",
            "1",
            "2"});
            this.comboBox5.Location = new System.Drawing.Point(6, 19);
            this.comboBox5.Name = "comboBox5";
            this.comboBox5.Size = new System.Drawing.Size(121, 21);
            this.comboBox5.TabIndex = 3;
            this.comboBox5.Text = "0";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.comboBox3);
            this.groupBox4.Location = new System.Drawing.Point(305, 509);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(143, 47);
            this.groupBox4.TabIndex = 4;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Stop bits";
            // 
            // comboBox3
            // 
            this.comboBox3.FormattingEnabled = true;
            this.comboBox3.Items.AddRange(new object[] {
            "1",
            "2"});
            this.comboBox3.Location = new System.Drawing.Point(6, 19);
            this.comboBox3.Name = "comboBox3";
            this.comboBox3.Size = new System.Drawing.Size(121, 21);
            this.comboBox3.TabIndex = 2;
            this.comboBox3.Text = "1";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.comboBox2);
            this.groupBox2.Location = new System.Drawing.Point(156, 509);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(143, 47);
            this.groupBox2.TabIndex = 4;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Speed";
            // 
            // comboBox2
            // 
            this.comboBox2.FormattingEnabled = true;
            this.comboBox2.Items.AddRange(new object[] {
            "1200",
            "2400",
            "4800",
            "9600",
            "19200"});
            this.comboBox2.Location = new System.Drawing.Point(6, 19);
            this.comboBox2.Name = "comboBox2";
            this.comboBox2.Size = new System.Drawing.Size(121, 21);
            this.comboBox2.TabIndex = 1;
            this.comboBox2.Text = "9600";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.comboBox1);
            this.groupBox3.Location = new System.Drawing.Point(7, 509);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(143, 47);
            this.groupBox3.TabIndex = 3;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "COM";
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "COM1",
            "COM2",
            "COM3",
            "COM4",
            "COM5",
            "COM6",
            "COM7",
            "COM8",
            "COM9",
            "COM10",
            "COM11",
            "COM12",
            "COM13",
            "COM14",
            "COM15",
            "COM16",
            "COM17",
            "COM18",
            "COM19",
            "COM20"});
            this.comboBox1.Location = new System.Drawing.Point(7, 20);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(121, 21);
            this.comboBox1.TabIndex = 0;
            this.comboBox1.Text = "COM1";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(752, 509);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(104, 47);
            this.button1.TabIndex = 1;
            this.button1.Text = "Validate";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.button3);
            this.groupBox1.Controls.Add(this.button2);
            this.groupBox1.Controls.Add(this.richTextBox1);
            this.groupBox1.Location = new System.Drawing.Point(7, 7);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(855, 476);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Log";
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(725, 429);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(124, 30);
            this.button3.TabIndex = 2;
            this.button3.Text = "Clean";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(19, 429);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(124, 30);
            this.button2.TabIndex = 1;
            this.button2.Text = "Save";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(7, 20);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.ReadOnly = true;
            this.richTextBox1.Size = new System.Drawing.Size(842, 403);
            this.richTextBox1.TabIndex = 0;
            this.richTextBox1.Text = "";
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.temperature_graph);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(868, 562);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Temperature";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // temperature_graph
            // 
            this.temperature_graph.BackColor = System.Drawing.Color.White;
            this.temperature_graph.ForeColor = System.Drawing.SystemColors.ActiveCaption;
            this.temperature_graph.Location = new System.Drawing.Point(7, 7);
            this.temperature_graph.Name = "temperature_graph";
            this.temperature_graph.Size = new System.Drawing.Size(855, 549);
            this.temperature_graph.TabIndex = 0;
            this.temperature_graph.XtraAutoScale = true;
            this.temperature_graph.XtraClassicLabels = true;
            this.temperature_graph.XtraFrame = false;
            this.temperature_graph.XtraLabelX = "Dernieres mesures";
            this.temperature_graph.XtraLabelY = "Temperature";
            this.temperature_graph.XtraLogX = false;
            this.temperature_graph.XtraLogY = false;
            this.temperature_graph.XtraMinLeftMargin = 0;
            this.temperature_graph.XtraSelectPoint = false;
            this.temperature_graph.XtraShowGrid = false;
            this.temperature_graph.XtraShowLegend = false;
            this.temperature_graph.XtraTitle = "Evolution de la temperature";
            this.temperature_graph.XtraUpdateCursor = true;
            this.temperature_graph.XtraXdigits = 0;
            this.temperature_graph.XtraXmax = 0F;
            this.temperature_graph.XtraXmin = 0F;
            this.temperature_graph.XtraXstep = 0F;
            this.temperature_graph.XtraYdigits = 0;
            this.temperature_graph.XtraYmax = 0F;
            this.temperature_graph.XtraYmin = 0F;
            this.temperature_graph.XtraYstep = 0F;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.pot_graph);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(868, 562);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Potentiometre";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // pot_graph
            // 
            this.pot_graph.BackColor = System.Drawing.Color.White;
            this.pot_graph.ForeColor = System.Drawing.SystemColors.ActiveCaption;
            this.pot_graph.Location = new System.Drawing.Point(7, 7);
            this.pot_graph.Name = "pot_graph";
            this.pot_graph.Size = new System.Drawing.Size(855, 549);
            this.pot_graph.TabIndex = 1;
            this.pot_graph.XtraAutoScale = true;
            this.pot_graph.XtraClassicLabels = true;
            this.pot_graph.XtraFrame = false;
            this.pot_graph.XtraLabelX = "Dernieres mesures";
            this.pot_graph.XtraLabelY = "Vpotentiometre";
            this.pot_graph.XtraLogX = false;
            this.pot_graph.XtraLogY = false;
            this.pot_graph.XtraMinLeftMargin = 0;
            this.pot_graph.XtraSelectPoint = false;
            this.pot_graph.XtraShowGrid = false;
            this.pot_graph.XtraShowLegend = false;
            this.pot_graph.XtraTitle = "Evolution de la tension aux bornes du potentiometre";
            this.pot_graph.XtraUpdateCursor = true;
            this.pot_graph.XtraXdigits = 0;
            this.pot_graph.XtraXmax = 0F;
            this.pot_graph.XtraXmin = 0F;
            this.pot_graph.XtraXstep = 0F;
            this.pot_graph.XtraYdigits = 0;
            this.pot_graph.XtraYmax = 0F;
            this.pot_graph.XtraYmin = 0F;
            this.pot_graph.XtraYstep = 0F;
            // 
            // serialPort1
            // 
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(901, 613);
            this.Controls.Add(this.tabControl1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Kurb";
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.groupBox6.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.tabPage2.ResumeLayout(false);
            this.tabPage3.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage3;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.ComboBox comboBox6;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.ComboBox comboBox5;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.ComboBox comboBox3;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.ComboBox comboBox2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button2;
        private componentXtra.XYGraph temperature_graph;
        private componentXtra.XYGraph pot_graph;
    }
}

