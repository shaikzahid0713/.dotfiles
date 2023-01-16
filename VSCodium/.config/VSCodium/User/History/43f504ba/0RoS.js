import React from 'react';
import { ReactDOM } from 'react';
import './index.css';

class Board extends React.Component {
    renderSquare(i) {
        return <Square value= {i} />;
    }
}