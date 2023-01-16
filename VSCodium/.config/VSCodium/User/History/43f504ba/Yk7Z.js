import React from 'react';
import { ReactDOM } from 'react';
import './index.css';

class Square extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            value: null,
        };
    }
    render() {
        return (
          <button className='square' onClick={() => console.log('click')}>
                {this.props.value}
            </button>
        );
    }
}

class Board extends React.Component {
    renderSquare(i) {
        return <Square value={i} />
    }
}