package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    TextView text;
    boolean flag=false;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        text = findViewById(R.id.textView);

        Button button = findViewById(R.id.myButton);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!flag) {
                    text.setText("ملک کے دو وزیراعظم ہونے چاہئیں. تقریر کے لئے یہی وزیراعظم ٹھیک ہے، ملک چلانے کے لیے کوئی اور ڈھونڈ لیں.");
                    flag = true;
                } else {
                    text.setText("There should be two Prime Ministers of the country. This is the prime minister for a speech, find someone else to run the country.");
                    flag = false;
                }
            }
        });
    }

}
