package com.acoustiguide;

import android.app.Activity;
import android.os.Bundle;
import android.widget.ImageView;
import butterknife.BindView;
import butterknife.ButterKnife;
import com.acoustiguide.Exhibition.R;


/**
 * @author lhunath, 2019-01-04
 */
public class ECActivity extends Activity {

    @BindView( R.id.frame_bottom )
    ImageView frame_bottom;

    @Override
    protected void onCreate(final Bundle savedInstanceState) {
        super.onCreate( savedInstanceState );

        setContentView( R.layout.activity_exhibition );
        ButterKnife.bind( this );
    }
}
